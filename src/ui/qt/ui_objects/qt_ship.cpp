#include "qt_ship.hpp"

#include <QPainter>

using biv::QtShip;

QtShip::QtShip(const Coord& top_left, int width, int height)
    : Ship(top_left, width, height),
      QtUIObjectRectAdapter(static_cast<const Rect&>(*this)) {}

void QtShip::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
) {
    painter->setBrush(Qt::darkBlue);
    painter->setPen(Qt::NoPen);

    painter->drawRect(boundingRect());
}
