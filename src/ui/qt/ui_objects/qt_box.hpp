#pragma once

#include <QGraphicsItem>

#include "qt_ui_obj_rect_adapter.hpp"
#include "objects/box.hpp"

namespace biv {

class QtBox : public QtUIObjectRectAdapter {
public:
    explicit QtBox(const Box& box);

    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;

private:
    const Box& box;
};

} // namespace biv
