#include "qt_enemy.hpp"

#include <QPainter>

using biv::QtEnemy;

QtEnemy::QtEnemy(const Enemy& e)
    : QtUIObjectRectAdapter(e.get_rect()),
      enemy(e) {}

void QtEnemy::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
) {
    painter->setBrush(Qt::darkGreen);
    painter->setPen(Qt::NoPen);

    painter->drawRect(boundingRect());
}
