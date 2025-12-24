#include "qt_game_map.hpp"

#include <algorithm>

using biv::QtGameMap;
using biv::QtUIObject;

QtGameMap::QtGameMap(int height, int width, QObject* parent)
    : QGraphicsScene(parent),
      GameMap(height, width) {

    constexpr int TILE_SIZE = 32;
    setSceneRect(0, 0, width * TILE_SIZE, height * TILE_SIZE);
}

void QtGameMap::add_obj(QtUIObject* obj) {
    objs.push_back(obj);
    addItem(obj);
}

void QtGameMap::clear() noexcept {
    // Background is managed by the view; nothing to clear here.
}

void QtGameMap::remove_obj(QtUIObject* obj) {
    removeItem(obj);
    objs.erase(std::remove(objs.begin(), objs.end(), obj), objs.end());
}

void QtGameMap::remove_objs() {
    for (QtUIObject* obj : objs) {
        removeItem(obj);
    }
    objs.clear();
}

void QtGameMap::refresh() noexcept {
    for (QtUIObject* obj : objs) {
        obj->sync_with_model();
    }
}

void QtGameMap::show() const noexcept {
    // Rendering is handled by a QGraphicsView; nothing to do here.
}
