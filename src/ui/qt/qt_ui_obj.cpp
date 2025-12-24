#include "qt_ui_obj.hpp"

using biv::QtUIObject;

QtUIObject::QtUIObject(const Rect& r)
    : rect(r) {}

QRectF QtUIObject::boundingRect() const {
    constexpr int TILE_SIZE = 32;
    const qreal width = (rect.get_right() - rect.get_left()) * TILE_SIZE;
    const qreal height = (rect.get_bottom() - rect.get_top()) * TILE_SIZE;
    return QRectF(0, 0, width, height);
}
