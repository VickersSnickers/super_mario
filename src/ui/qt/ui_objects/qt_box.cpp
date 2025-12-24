#include "qt_box.hpp"

#include <QPainter>

using biv::QtBox;

QtBox::QtBox(const Coord& top_left, int width, int height)
    : Box(top_left, width, height),
      QtUIObjectRectAdapter(static_cast<const Rect&>(*this)) {}

void QtBox::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
) {
    painter->setBrush(Qt::darkGray);
    painter->setPen(Qt::NoPen);

    painter->drawRect(boundingRect());
}
