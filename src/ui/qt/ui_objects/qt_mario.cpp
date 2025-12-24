#include "qt_mario.hpp"

#include <QPainter>

using biv::QtMario;

QtMario::QtMario(const Coord& top_left, int width, int height)
    : Mario(top_left, width, height),
      QtUIObjectRectAdapter(static_cast<const Rect&>(*this)) {}

void QtMario::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
) {
    painter->setBrush(Qt::red);
    painter->setPen(Qt::NoPen);

    painter->drawRect(boundingRect());
}
