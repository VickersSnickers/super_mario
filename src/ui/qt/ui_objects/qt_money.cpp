#include "qt_money.hpp"

#include <QPainter>

using biv::QtMoney;

QtMoney::QtMoney(const Coord& top_left, int width, int height)
    : Money(top_left, width, height),
      QtUIObjectRectAdapter(static_cast<const Rect&>(*this)) {}

void QtMoney::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
) {
    painter->setBrush(Qt::yellow);
    painter->setPen(Qt::NoPen);

    painter->drawEllipse(boundingRect());
}
