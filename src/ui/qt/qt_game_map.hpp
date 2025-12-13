#pragma once

#include <vector>

#include <QGraphicsScene>

#include "game_map.hpp"
#include "qt_ui_obj.hpp"

namespace biv {

class QtGameMap : public QGraphicsScene, public GameMap {
    Q_OBJECT

private:
    std::vector<QtUIObject*> objs;

public:
    QtGameMap(int height, int width, QObject* parent = nullptr);
    ~QtGameMap() override = default;

    void add_obj(QtUIObject*);
    void refresh() noexcept override;
    void remove_obj(QtUIObject*);
    void remove_objs() override;
};

}
