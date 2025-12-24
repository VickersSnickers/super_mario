#pragma once

#include "qt_ui_obj.hpp"
#include "rect.hpp"

namespace biv {

class QtUIObjectRectAdapter : public QtUIObject {
public:
    explicit QtUIObjectRectAdapter(const Rect& rect);

    void sync_with_model() override;

protected:
    static constexpr int TILE_SIZE = 32;
};

}
