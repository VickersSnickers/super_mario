#include "qt_jumping_enemy.hpp"

#include <QPainter>

using biv::QtJumpingEnemy;

QtJumpingEnemy::QtJumpingEnemy(const Coord& top_left, int width, int height)
    : JumpingEnemy(top_left, width, height),
      QtUIObjectRectAdapter(static_cast<const Rect&>(*this)) {}

void QtJumpingEnemy::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
) {
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::NoPen);

    painter->drawRect(boundingRect());
}
