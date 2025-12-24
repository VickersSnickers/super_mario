#include "qt_ui_obj_rect_adapter.hpp"

using biv::QtUIObjectRectAdapter;

QtUIObjectRectAdapter::QtUIObjectRectAdapter(const Rect& r)
    : QtUIObject(r) {
    sync_with_model();
}

void QtUIObjectRectAdapter::sync_with_model() {
    setPos(
        rect.get_left() * TILE_SIZE,
        rect.get_top() * TILE_SIZE
    );
}
