#include "console_flying_enemy.hpp"

using biv::ConsoleFlyingEnemy;

ConsoleFlyingEnemy::ConsoleFlyingEnemy(const Coord& top_left, const int width, const int height,
const float left_bound, const float right_bound
)
    : FlyingEnemy(top_left, width, height, left_bound, right_bound) {}

char ConsoleFlyingEnemy::get_brush() const noexcept {
    return 'f';
}