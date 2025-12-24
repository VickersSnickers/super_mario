#pragma once

#include <QGraphicsItem>

#include "objects/jumping_enemy.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {

class QtJumpingEnemy : public JumpingEnemy, public QtUIObjectRectAdapter {
public:
    QtJumpingEnemy(const Coord& top_left, int width, int height);

    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;
};

} // namespace biv
