#pragma once

#include <QGraphicsItem>

#include "objects/ship.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {

class QtShip : public Ship, public QtUIObjectRectAdapter {
public:
    QtShip(const Coord& top_left, int width, int height);

    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;
};

} // namespace biv
