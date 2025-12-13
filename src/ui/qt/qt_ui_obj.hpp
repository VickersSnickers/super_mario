#pragma once

#include <QGraphicsItem>

#include "rect.hpp"

namespace biv {

class QtUIObject : public QGraphicsItem {
public:
    explicit QtUIObject(const Rect& rect);
    ~QtUIObject() override = default;

    virtual void sync_with_model() = 0;

protected:
    const Rect& rect;

    QRectF boundingRect() const override;
};

}
