#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "flying_enemy.hpp"

namespace biv {
    class ConsoleFlyingEnemy : public FlyingEnemy, public ConsoleUIObjectRectAdapter {
        public:
            ConsoleFlyingEnemy(const Coord& top_left, const int width, const int height,
            const float left_bound, const float right_bound);

            char get_brush() const noexcept override;
    };
}