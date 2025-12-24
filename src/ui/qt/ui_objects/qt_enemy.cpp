#include "qt_enemy.hpp"

#include <QPainter>

using biv::QtEnemy;

QtEnemy::QtEnemy(const Coord& top_left, int width, int height)
    : Enemy(top_left, width, height),
      QtUIObjectRectAdapter(static_cast<const Rect&>(*this)) {}

void QtEnemy::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
) {
    painter->setBrush(Qt::darkGreen);
    painter->setPen(Qt::NoPen);

    painter->drawRect(boundingRect());
}
