#include "jumping_enemy.hpp"

using biv::JumpingEnemy;

JumpingEnemy::JumpingEnemy(const Coord& top_left, const int width, const int height)
    : Enemy(top_left, width, height) {}

void JumpingEnemy::move_vertically() noexcept {
    if (is_grounded_) {
        jump();
        is_grounded_ = false;
    }

    Movable::move_vertically();
}

void JumpingEnemy::move_horizontally() noexcept {
    if (ground_ != nullptr) {
        float next_left = top_left.x + hspeed;
        float next_right = next_left + width;

        if (next_left < ground_->get_left() || next_right > ground_->get_right()) {
            hspeed = -hspeed;
            next_left = top_left.x + hspeed;
            next_right = next_left + width;

            if (next_left < ground_->get_left()) {
                top_left.x = ground_->get_left();
            } else if (next_right > ground_->get_right()) {
                top_left.x = ground_->get_right() - width;
            }
        }
        }

        Movable::move_horizontally();
}

void JumpingEnemy::process_vertical_static_collision(Rect* obj) noexcept {
    const bool was_falling = vspeed > 0;
    Enemy::process_vertical_static_collision(obj);
    if (was_falling) {
        is_grounded_ = true;
        ground_ = obj;
    }
}