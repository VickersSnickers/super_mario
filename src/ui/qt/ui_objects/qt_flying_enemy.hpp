#pragma once

#include <QGraphicsItem>

#include "objects/flying_enemy.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {

class QtFlyingEnemy : public FlyingEnemy, public QtUIObjectRectAdapter {
public:
    QtFlyingEnemy(const Coord& top_left, int width, int height, float left_bound, float right_bound);

    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;
};

} // namespace biv
