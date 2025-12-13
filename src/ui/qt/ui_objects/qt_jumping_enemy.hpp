#pragma once

#include <QGraphicsItem>

#include "qt_ui_obj_rect_adapter.hpp"
#include "objects/jumping_enemy.hpp"

namespace biv {

class QtJumpingEnemy : public QtUIObjectRectAdapter {
public:
    explicit QtJumpingEnemy(const JumpingEnemy& enemy);

    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;

private:
    const JumpingEnemy& enemy;
};

} // namespace biv
