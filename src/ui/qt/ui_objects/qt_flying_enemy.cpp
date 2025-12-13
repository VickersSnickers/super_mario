#pragma once

#include <QGraphicsItem>

#include "qt_ui_obj_rect_adapter.hpp"
#include "objects/flying_enemy.hpp"

namespace biv {

class QtFlyingEnemy : public QtUIObjectRectAdapter {
public:
    explicit QtFlyingEnemy(const FlyingEnemy& enemy);

    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;

private:
    const FlyingEnemy& enemy;
};

} // namespace biv
