#pragma once

#include <QGraphicsItem>

#include "qt_ui_obj_rect_adapter.hpp"
#include "objects/money.hpp"

namespace biv {

class QtMoney : public QtUIObjectRectAdapter {
public:
    explicit QtMoney(const Money& money);

    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;

private:
    const Money& money;
};

} // namespace biv
