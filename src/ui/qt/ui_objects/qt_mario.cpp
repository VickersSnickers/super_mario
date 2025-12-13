#include "qt_mario.hpp"

#include <QPainter>

using biv::QtMario;

QtMario::QtMario(const Mario& m)
    : QtUIObjectRectAdapter(m.get_rect()),
      mario(m) {}

void QtMario::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
) {
    painter->setBrush(Qt::red);
    painter->setPen(Qt::NoPen);

    painter->drawRect(boundingRect());
}
