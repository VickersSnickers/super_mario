#pragma once

#include <vector>

#include "ui_factory.hpp"

#include "qt_game_map.hpp"

#include "ui_objects/qt_box.hpp"
#include "ui_objects/qt_full_box.hpp"
#include "ui_objects/qt_enemy.hpp"
#include "ui_objects/qt_flying_enemy.hpp"
#include "ui_objects/qt_jumping_enemy.hpp"
#include "ui_objects/qt_mario.hpp"
#include "ui_objects/qt_money.hpp"
#include "ui_objects/qt_ship.hpp"

namespace biv {

class QtUIFactory : public UIFactory {
private:
    QtGameMap* game_map = nullptr;

    std::vector<QtBox*> boxes;
    std::vector<QtFullBox*> full_boxes;
    std::vector<QtShip*> ships;

    QtMario* mario = nullptr;

    std::vector<QtEnemy*> enemies;
    std::vector<QtFlyingEnemy*> flying_enemies;
    std::vector<QtJumpingEnemy*> jumping_enemies;
    std::vector<QtMoney*> moneys;

public:
    explicit QtUIFactory(Game* game);
    ~QtUIFactory() override;

    void clear_data() override;

    void create_box(const Coord&, int, int) override;
    void create_enemy(const Coord&, int, int) override;
    void create_flying_enemy(const Coord&, int, int, float, float) override;
    void create_jumping_enemy(const Coord&, int, int) override;
    void create_full_box(const Coord&, int, int) override;
    void create_mario(const Coord&, int, int) override;
    void create_money(const Coord&, int, int) override;
    void create_ship(const Coord&, int, int) override;

    GameMap* get_game_map() override;
    Mario* get_mario() override;

private:
    void create_game_map() override;
};

} // namespace biv
