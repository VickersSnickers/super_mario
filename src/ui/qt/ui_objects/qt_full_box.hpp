#pragma once

#include <QGraphicsItem>

#include "objects/full_box.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {

class QtFullBox : public FullBox, public QtUIObjectRectAdapter {
public:
    QtFullBox(const Coord& top_left, int width, int height, UIFactory* ui_factory);

    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;
};

} // namespace biv
