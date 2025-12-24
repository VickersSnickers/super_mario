#include "qt_game_window.hpp"

#include <QGuiApplication>
#include <QKeyEvent>
#include <QPainter>
#include <QScreen>
#include <QString>
#include <algorithm>

#include "mario.hpp"
#include "qt_game_map.hpp"

QtGameWindow::QtGameWindow(biv::QtGameMap* game_map, QWidget* parent)
    : QGraphicsView(parent),
      game_map_(game_map) {
    setRenderHint(QPainter::Antialiasing, true);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFocusPolicy(Qt::StrongFocus);

    if (game_map_) {
        setScene(game_map_);
        setSceneRect(game_map_->sceneRect());
    }

    adjust_window_size();
    apply_view_scale();
}

bool QtGameWindow::is_move_left() const {
    return move_left_;
}

bool QtGameWindow::is_move_right() const {
    return move_right_;
}

bool QtGameWindow::take_jump_requested() {
    if (!jump_requested_) {
        return false;
    }
    jump_requested_ = false;
    return true;
}

bool QtGameWindow::take_exit_requested() {
    if (!exit_requested_) {
        return false;
    }
    exit_requested_ = false;
    return true;
}

void QtGameWindow::position_camera_on_mario(const biv::Mario* mario) {
    if (!mario) {
        return;
    }

    const auto rect = mario->get_rect();
    const qreal mario_center_x = (rect.get_left() + rect.get_right()) / 2.0;
    const qreal mario_center_y = (rect.get_top() + rect.get_bottom()) / 2.0;

    const qreal sx = std::max(transform().m11(), 0.0001);
    const qreal view_w_scene = viewport()->width() / sx;

    const qreal mario_left_of_center = view_w_scene * 0.10;
    centerOnClamped(mario_center_x - mario_left_of_center, mario_center_y);
}

void QtGameWindow::keyPressEvent(QKeyEvent* event) {
    if (event->isAutoRepeat()) {
        return;
    }
    const QString key_text = event->text().toLower();
    switch (event->key()) {
        case Qt::Key_A:
        case Qt::Key_Left:
            move_left_ = true;
            break;
        case Qt::Key_D:
        case Qt::Key_Right:
            move_right_ = true;
            break;
        case Qt::Key_Space:
        case Qt::Key_W:
        case Qt::Key_Up:
            jump_requested_ = true;
            break;
        case Qt::Key_Escape:
            exit_requested_ = true;
            break;
        default:
            if (key_text == "a" || key_text == "ф") {
                move_left_ = true;
            } else if (key_text == "d" || key_text == "в") {
                move_right_ = true;
            } else if (key_text == "w" || key_text == "ц") {
                jump_requested_ = true;
            } else {
                QGraphicsView::keyPressEvent(event);
            }
    }
}

void QtGameWindow::keyReleaseEvent(QKeyEvent* event) {
    if (event->isAutoRepeat()) {
        return;
    }
    const QString key_text = event->text().toLower();
    switch (event->key()) {
        case Qt::Key_A:
        case Qt::Key_Left:
            move_left_ = false;
            break;
        case Qt::Key_D:
        case Qt::Key_Right:
            move_right_ = false;
            break;
        case Qt::Key_Space:
        case Qt::Key_W:
        case Qt::Key_Up:
            break;
        default:
            if (key_text == "a" || key_text == "ф") {
                move_left_ = false;
            } else if (key_text == "d" || key_text == "в") {
                move_right_ = false;
            } else {
                QGraphicsView::keyReleaseEvent(event);
            }
    }
}

void QtGameWindow::adjust_window_size() {
    const QSize scene_size = sceneRect().size().toSize();
    const QRect available_geometry =
        QGuiApplication::primaryScreen() ? QGuiApplication::primaryScreen()->availableGeometry()
                                         : QRect(0, 0, 1280, 720);

    const int max_width = static_cast<int>(available_geometry.width() * 0.8);
    const int max_height = static_cast<int>(available_geometry.height() * 0.8);

    const QSize target_size(
        std::min(scene_size.width(), max_width),
        std::min(scene_size.height(), max_height));

    setFixedSize(target_size);
}

void QtGameWindow::apply_view_scale() {
    static constexpr qreal VIEW_SCALE = 0.60;

    resetTransform();
    scale(VIEW_SCALE, VIEW_SCALE);
}

void QtGameWindow::centerOnClamped(qreal scene_x, qreal scene_y) {
    const QRectF sr = sceneRect();

    const qreal sx = std::max(transform().m11(), 0.0001);
    const qreal sy = std::max(transform().m22(), 0.0001);
    const qreal half_w = (viewport()->width() / sx) * 0.5;
    const qreal half_h = (viewport()->height() / sy) * 0.5;

    const qreal min_x = sr.left() + half_w;
    const qreal max_x = sr.right() - half_w;
    const qreal min_y = sr.top() + half_h;
    const qreal max_y = sr.bottom() - half_h;

    qreal cx = scene_x;
    qreal cy = scene_y;

    if (max_x >= min_x) {
        cx = std::clamp(scene_x, min_x, max_x);
    } else {
        cx = sr.center().x();
    }

    if (max_y >= min_y) {
        cy = std::clamp(scene_y, min_y, max_y);
    } else {
        cy = sr.center().y();
    }

    centerOn(cx, cy);
}