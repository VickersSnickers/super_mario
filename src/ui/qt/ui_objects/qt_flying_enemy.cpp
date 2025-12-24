#include "qt_flying_enemy.hpp"

#include <QPainter>

using biv::QtFlyingEnemy;

QtFlyingEnemy::QtFlyingEnemy(
    const Coord& top_left, int width, int height, float left_bound, float right_bound)
    : FlyingEnemy(top_left, width, height, left_bound, right_bound),
      QtUIObjectRectAdapter(static_cast<const Rect&>(*this)) {}

void QtFlyingEnemy::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
) {
    painter->setBrush(Qt::darkCyan);
    painter->setPen(Qt::NoPen);

    painter->drawEllipse(boundingRect());
}
