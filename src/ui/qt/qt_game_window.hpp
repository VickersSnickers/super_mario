#pragma once

#include <QGraphicsView>

namespace biv {
class Mario;
class QtGameMap;
}

class QtGameWindow : public QGraphicsView {
public:
    explicit QtGameWindow(biv::QtGameMap* game_map, QWidget* parent = nullptr);

    bool is_move_left() const;
    bool is_move_right() const;
    bool take_jump_requested();
    bool take_exit_requested();

    void position_camera_on_mario(const biv::Mario* mario);

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

private:
    void adjust_window_size();
    void apply_view_scale();
    void centerOnClamped(qreal scene_x, qreal scene_y);

    biv::QtGameMap* game_map_ = nullptr;
    bool move_left_ = false;
    bool move_right_ = false;
    bool jump_requested_ = false;
    bool exit_requested_ = false;
};