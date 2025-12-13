#include "qt_box.hpp"

#include <QPainter>

using biv::QtBox;

QtBox::QtBox(const Box& b)
    : QtUIObjectRectAdapter(b.get_rect()),
      box(b) {}

void QtBox::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
) {
    painter->setBrush(Qt::darkGray);
    painter->setPen(Qt::NoPen);

    painter->drawRect(boundingRect());
}
