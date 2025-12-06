#include "flying_enemy.hpp"

#include <cmath>

using biv::FlyingEnemy;

FlyingEnemy::FlyingEnemy(const Coord& top_left, const int width, const int height,
    const float left_bound, const float right_bound
)
    : Enemy(top_left, width, height), left_bound(left_bound), right_bound(right_bound) {}

void FlyingEnemy::process_mario_collision(Collisionable* mario) noexcept {
    mario->kill();
}

void FlyingEnemy::move_horizontally() noexcept {
    const float next_x = top_left.x + hspeed;

    if (next_x < left_bound) {
        top_left.x = left_bound;
        hspeed = std::abs(hspeed);
    } else if (next_x + width > right_bound) {
        top_left.x = right_bound - width;
        hspeed = -std::abs(hspeed);
    } else {
        top_left.x = next_x;
    }
}

void FlyingEnemy::move_vertically() noexcept {
    static constexpr float OSCILLATION_SPEED = 0.08f;
    static constexpr float OSCILLATION_AMPLITUDE = 2.0f;

    const float previous_offset = std::sin(oscillation_phase) * OSCILLATION_AMPLITUDE;
    oscillation_phase += OSCILLATION_SPEED;
    const float new_offset = std::sin(oscillation_phase) * OSCILLATION_AMPLITUDE;

    top_left.y += new_offset - previous_offset;
}

void FlyingEnemy::move_map_left() noexcept {
    RectMapMovableAdapter::move_map_left();
    left_bound -= MapMovable::MAP_STEP;
    right_bound -= MapMovable::MAP_STEP;
}

void FlyingEnemy::move_map_right() noexcept {
    RectMapMovableAdapter::move_map_right();
    left_bound += MapMovable::MAP_STEP;
    right_bound += MapMovable::MAP_STEP;
}

void FlyingEnemy::process_vertical_static_collision(Rect*) noexcept {}