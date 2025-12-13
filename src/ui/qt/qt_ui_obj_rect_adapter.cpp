#include "qt_ui_obj_rect_adapter.hpp"

using biv::QtUIObjectRectAdapter;

QtUIObjectRectAdapter::QtUIObjectRectAdapter(const Rect& r)
    : QtUIObject(r) {
    sync_with_model();
}

void QtUIObjectRectAdapter::sync_with_model() {
    setPos(
        rect.left * TILE_SIZE,
        rect.top * TILE_SIZE
    );
}
