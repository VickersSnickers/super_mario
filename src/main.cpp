#include <QApplication>
#include <QGraphicsView>
#include <QGuiApplication>
#include <QKeyEvent>
#include <QPainter>
#include <QScreen>
#include <QTimer>
#include <algorithm>
#include <memory>

#include "first_level.hpp"
#include "game.hpp"
#include "game_level.hpp"
#include "mario.hpp"
#include "qt_game_map.hpp"
#include "qt_ui_factory.hpp"

class GameWindow : public QGraphicsView {
public:
    explicit GameWindow(QWidget* parent = nullptr)
        : QGraphicsView(parent) {
        setRenderHint(QPainter::Antialiasing, true);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFocusPolicy(Qt::StrongFocus);

        game = std::make_unique<biv::Game>();
        ui_factory = std::make_unique<biv::QtUIFactory>(game.get());
        game_level = std::make_unique<biv::FirstLevel>(ui_factory.get());
        game_map = static_cast<biv::QtGameMap*>(ui_factory->get_game_map());
        mario = ui_factory->get_mario();

        setScene(game_map);
        setSceneRect(game_map->sceneRect());

        adjust_window_size();
        apply_view_scale(); 
        position_camera_on_mario();

        connect(&timer, &QTimer::timeout, this, &GameWindow::tick);
        timer.start(16);
    }

protected:
    void keyPressEvent(QKeyEvent* event) override {
        if (event->isAutoRepeat()) {
            return;
        }
        switch (event->key()) {
            case Qt::Key_A:
            case Qt::Key_Left:
                move_right = true;
                break;
            case Qt::Key_D:
            case Qt::Key_Right:
                move_left = true;
                break;
            case Qt::Key_Space:
            case Qt::Key_W:
            case Qt::Key_Up:
                jump_requested = true;
                break;
            case Qt::Key_Escape:
                game->finish();
                close();
                break;
            default:
                QGraphicsView::keyPressEvent(event);
        }
    }

    void keyReleaseEvent(QKeyEvent* event) override {
        if (event->isAutoRepeat()) {
            return;
        }
        switch (event->key()) {
            case Qt::Key_A:
            case Qt::Key_Left:
                move_right = false;
                break;
            case Qt::Key_D:
            case Qt::Key_Right:
                move_left = false;
                break;
            case Qt::Key_Space:
            case Qt::Key_W:
            case Qt::Key_Up:
                break;
            default:
                QGraphicsView::keyReleaseEvent(event);
        }
    }

private:
    void tick() {
        if (game->is_finished()) {
            close();
            return;
        }

        handle_input();

        game->move_objs_horizontally();
        game->check_horizontally_static_collisions();

        game->move_objs_vertically();
        game->check_mario_collision();
        game->check_vertically_static_collisions();

        if (game_map->is_below_map(mario->get_top()) || !mario->is_active()) {
            game_level->restart();
            mario = ui_factory->get_mario();
            position_camera_on_mario();
        }

        if (game->is_level_end()) {
            if (!game_level->is_final()) {
                game_level.reset(game_level->get_next());
                mario = ui_factory->get_mario();
                game->start_level();
                position_camera_on_mario();
            } else {
                game->finish();
                close();
            }
        }

        game_map->refresh();
    }

    void handle_input() {
        if (jump_requested) {
            mario->jump();
            jump_requested = false;
        }

        if (move_left && !move_right) {
            mario->move_map_left();
            if (!game->check_static_collisions(mario)) {
                game->move_map_left();
            }
            mario->move_map_right();
        } else if (move_right && !move_left) {
            mario->move_map_right();
            if (!game->check_static_collisions(mario)) {
                game->move_map_right();
            }
            mario->move_map_left();
        }
    }

    void adjust_window_size() {
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

    void apply_view_scale() {
        static constexpr qreal VIEW_SCALE = 0.60;

        resetTransform();
        scale(VIEW_SCALE, VIEW_SCALE);
    }

    void centerOnClamped(qreal scene_x, qreal scene_y) {
        const QRectF sr = sceneRect();

        // Размер видимой области в координатах сцены (с учётом текущего transform)
        const qreal sx = std::max(transform().m11(), 0.0001);
        const qreal sy = std::max(transform().m22(), 0.0001);
        const qreal half_w = (viewport()->width()  / sx) * 0.5;
        const qreal half_h = (viewport()->height() / sy) * 0.5;

        const qreal min_x = sr.left() + half_w;
        const qreal max_x = sr.right() - half_w;
        const qreal min_y = sr.top() + half_h;
        const qreal max_y = sr.bottom() - half_h;

        qreal cx = scene_x;
        qreal cy = scene_y;

        if (max_x >= min_x) cx = std::clamp(scene_x, min_x, max_x);
        else                cx = sr.center().x();

        if (max_y >= min_y) cy = std::clamp(scene_y, min_y, max_y);
        else                cy = sr.center().y();

        centerOn(cx, cy);
    }

    void position_camera_on_mario() {
        if (!mario) return;

        const auto rect = mario->get_rect();
        const qreal mario_center_x = (rect.get_left() + rect.get_right()) / 2.0;
        const qreal mario_center_y = (rect.get_top() + rect.get_bottom()) / 2.0;

        const qreal sx = std::max(transform().m11(), 0.0001);
        const qreal view_w_scene = viewport()->width() / sx;

        const qreal mario_left_of_center = view_w_scene * 0.10;
        centerOnClamped(mario_center_x - mario_left_of_center, mario_center_y);
    }

private:
    std::unique_ptr<biv::Game> game;
    std::unique_ptr<biv::UIFactory> ui_factory;
    std::unique_ptr<biv::GameLevel> game_level;
    biv::QtGameMap* game_map = nullptr;
    biv::Mario* mario = nullptr;

    bool move_left = false;
    bool move_right = false;
    bool jump_requested = false;

    QTimer timer;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    GameWindow window;
    window.show();

    return QApplication::exec();
}

