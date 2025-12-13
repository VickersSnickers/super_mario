#pragma once

#include <QGraphicsItem>

#include "qt_ui_obj_rect_adapter.hpp"
#include "objects/full_box.hpp"

namespace biv {

class QtFullBox : public QtUIObjectRectAdapter {
public:
    explicit QtFullBox(const FullBox& box);

    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;

private:
    const FullBox& box;
};

} // namespace biv
