#pragma once

#include <QGraphicsItem>

#include "box.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {

class QtBox : public Box, public QtUIObjectRectAdapter {
public:
    QtBox(const Coord& top_left, int width, int height);

    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;
};

} // namespace biv
