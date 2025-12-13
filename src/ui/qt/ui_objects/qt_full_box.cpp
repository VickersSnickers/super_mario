#include "qt_full_box.hpp"

#include <QPainter>

using biv::QtFullBox;

QtFullBox::QtFullBox(const FullBox& b)
    : QtUIObjectRectAdapter(b.get_rect()),
      box(b) {}

void QtFullBox::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
) {
    if (box.is_active()) {
        painter->setBrush(Qt::yellow); // активная — жёлтая
    } else {
        painter->setBrush(Qt::darkGray); // неактивная — тёмно-серая
    }

    painter->setPen(Qt::NoPen);
    painter->drawRect(boundingRect());
}
