#include "qt_full_box.hpp"

#include <QPainter>

using biv::QtFullBox;

QtFullBox::QtFullBox(const Coord& top_left, int width, int height, UIFactory* ui_factory)
    : FullBox(top_left, width, height, ui_factory),
      QtUIObjectRectAdapter(static_cast<const Rect&>(*this)) {}

void QtFullBox::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
) {
    if (is_active()) {
        painter->setBrush(Qt::yellow); // активная — жёлтая
    } else {
        painter->setBrush(Qt::darkGray); // неактивная — тёмно-серая
    }

    painter->setPen(Qt::NoPen);
    painter->drawRect(boundingRect());
}
