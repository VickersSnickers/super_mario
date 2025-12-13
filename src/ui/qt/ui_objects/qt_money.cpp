#include "qt_money.hpp"

#include <QPainter>

using biv::QtMoney;

QtMoney::QtMoney(const Money& m)
    : QtUIObjectRectAdapter(m.get_rect()),
      money(m) {}

void QtMoney::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
) {
    painter->setBrush(Qt::yellow);
    painter->setPen(Qt::NoPen);

    painter->drawEllipse(boundingRect());
}
