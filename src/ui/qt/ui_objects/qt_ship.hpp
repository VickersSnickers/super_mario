#pragma once

#include <QGraphicsItem>

#include "qt_ui_obj_rect_adapter.hpp"
#include "objects/ship.hpp"

namespace biv {

class QtShip : public QtUIObjectRectAdapter {
public:
    explicit QtShip(const Ship& ship);

    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;

private:
    const Ship& ship;
};

} // namespace biv
