#include "qt_jumping_enemy.hpp"

#include <QPainter>

using biv::QtJumpingEnemy;

QtJumpingEnemy::QtJumpingEnemy(const JumpingEnemy& e)
    : QtUIObjectRectAdapter(e.get_rect()),
      enemy(e) {}

void QtJumpingEnemy::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
) {
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::NoPen);

    painter->drawRect(boundingRect());
}
