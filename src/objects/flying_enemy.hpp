#pragma once

#include "enemy.hpp"

namespace biv {
    class FlyingEnemy : public Enemy {
            public:
                FlyingEnemy(const Coord& top_left, const int width, const int height,
                const float left_bound, const float right_bound);

                void move_horizontally() noexcept override;
                void move_vertically() noexcept override;
                void move_map_left() noexcept override;
                void move_map_right() noexcept override;
                void process_vertical_static_collision(Rect*) noexcept override;
                void process_mario_collision(Collisionable*) noexcept override;

            private:
                float left_bound;
                float right_bound;
                float oscillation_phase = 0.0f;
    };
}