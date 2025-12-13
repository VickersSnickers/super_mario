#include "qt_ship.hpp"

#include <QPainter>

using biv::QtShip;

QtShip::QtShip(const Ship& s)
    : QtUIObjectRectAdapter(s.get_rect()),
      ship(s) {}

void QtShip::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
) {
    painter->setBrush(Qt::darkBlue);
    painter->setPen(Qt::NoPen);

    painter->drawRect(boundingRect());
}
