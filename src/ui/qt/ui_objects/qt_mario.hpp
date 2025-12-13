#pragma once

#include <QGraphicsItem>

#include "qt_ui_obj_rect_adapter.hpp"
#include "objects/mario.hpp"

namespace biv {

class QtMario : public QtUIObjectRectAdapter {
public:
    explicit QtMario(const Mario& mario);

    // Отрисовка
    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;

private:
    const Mario& mario;
};

} // namespace biv
