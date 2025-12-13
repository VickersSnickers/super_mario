#pragma once

#include <QGraphicsItem>

#include "qt_ui_obj_rect_adapter.hpp"
#include "objects/enemy.hpp"

namespace biv {

class QtEnemy : public QtUIObjectRectAdapter {
public:
    explicit QtEnemy(const Enemy& enemy);

    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr
    ) override;

private:
    const Enemy& enemy;
};

}
