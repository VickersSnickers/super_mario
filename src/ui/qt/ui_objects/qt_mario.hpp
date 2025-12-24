#pragma once

#include <QGraphicsItem>

#include "objects/mario.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {

class QtMario : public Mario, public QtUIObjectRectAdapter {
public:
    QtMario(const Coord& top_left, int width, int height);

    // Отрисовка
    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;
};

} // namespace biv
