#include "qt_ui_obj.hpp"

using biv::QtUIObject;

QtUIObject::QtUIObject(const Rect& r)
    : rect(r) {}

QRectF QtUIObject::boundingRect() const {
    constexpr int TILE_SIZE = 32;
    return QRectF(
        rect.left * TILE_SIZE,
        rect.top * TILE_SIZE,
        rect.width * TILE_SIZE,
        rect.height * TILE_SIZE
    );
}
