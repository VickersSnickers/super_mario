#pragma once

#include <QGraphicsItem>

#include "objects/enemy.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {

class QtEnemy : public Enemy, public QtUIObjectRectAdapter {
public:
    QtEnemy(const Coord& top_left, int width, int height);

    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;
};

}
