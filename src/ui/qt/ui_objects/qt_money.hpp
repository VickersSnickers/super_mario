#pragma once

#include <QGraphicsItem>

#include "objects/money.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {

class QtMoney : public Money, public QtUIObjectRectAdapter {
public:
    QtMoney(const Coord& top_left, int width, int height);

    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;
};

} // namespace biv
