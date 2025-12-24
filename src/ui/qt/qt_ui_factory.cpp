#include "qt_ui_factory.hpp"

namespace biv {

QtUIFactory::QtUIFactory(Game* game)
    : UIFactory(game) {
    create_game_map();
}

QtUIFactory::~QtUIFactory() {
    clear_data();
    delete game_map;
    game_map = nullptr;
}

void QtUIFactory::clear_data() {
    game->remove_objs();
    game_map->remove_objs();

    delete mario;
    mario = nullptr;

    for (auto* box : boxes) {
        delete box;
    }
    boxes.clear();

    for (auto* box : full_boxes) {
        delete box;
    }
    full_boxes.clear();

    for (auto* ship : ships) {
        delete ship;
    }
    ships.clear();

    for (auto* enemy : enemies) {
        delete enemy;
    }
    enemies.clear();

    for (auto* enemy : flying_enemies) {
        delete enemy;
    }
    flying_enemies.clear();

    for (auto* enemy : jumping_enemies) {
        delete enemy;
    }
    jumping_enemies.clear();

    for (auto* money : moneys) {
        delete money;
    }
    moneys.clear();
}

void QtUIFactory::create_box(const Coord& top_left, int width, int height) {
    auto* box = new QtBox(top_left, width, height);
    boxes.push_back(box);

    game->add_map_movable(box);
    game->add_static_obj(box);
    game_map->add_obj(box);
}

void QtUIFactory::create_enemy(const Coord& top_left, int width, int height) {
    auto* enemy = new QtEnemy(top_left, width, height);
    enemies.push_back(enemy);

    game->add_map_movable(enemy);
    game->add_movable(enemy);
    game->add_collisionable(enemy);
    game_map->add_obj(enemy);
}

void QtUIFactory::create_flying_enemy(
    const Coord& top_left, int width, int height, float left_bound, float right_bound) {
    auto* enemy = new QtFlyingEnemy(top_left, width, height, left_bound, right_bound);
    flying_enemies.push_back(enemy);

    game->add_map_movable(enemy);
    game->add_movable(enemy);
    game->add_collisionable(enemy);
    game_map->add_obj(enemy);
}

void QtUIFactory::create_jumping_enemy(const Coord& top_left, int width, int height) {
    auto* enemy = new QtJumpingEnemy(top_left, width, height);
    jumping_enemies.push_back(enemy);

    game->add_map_movable(enemy);
    game->add_movable(enemy);
    game->add_collisionable(enemy);
    game_map->add_obj(enemy);
}

void QtUIFactory::create_full_box(const Coord& top_left, int width, int height) {
    auto* box = new QtFullBox(top_left, width, height, this);
    full_boxes.push_back(box);

    game->add_collisionable(box);
    game->add_map_movable(box);
    game->add_static_obj(box);
    game_map->add_obj(box);
}

void QtUIFactory::create_mario(const Coord& top_left, int width, int height) {
    if (mario) {
        game->remove_collisionable(mario);
        game->remove_movable(mario);
        game->remove_mario();
        game_map->remove_obj(mario);
        delete mario;
    }

    mario = new QtMario(top_left, width, height);

    game->add_collisionable(mario);
    game->add_movable(mario);
    game->add_mario(mario);
    game_map->add_obj(mario);
}

void QtUIFactory::create_money(const Coord& top_left, int width, int height) {
    auto* money = new QtMoney(top_left, width, height);
    moneys.push_back(money);

    game->add_map_movable(money);
    game->add_movable(money);
    game->add_collisionable(money);
    game_map->add_obj(money);
}

void QtUIFactory::create_ship(const Coord& top_left, int width, int height) {
    auto* ship = new QtShip(top_left, width, height);
    ships.push_back(ship);

    game->add_map_movable(ship);
    game->add_static_obj(ship);
    game_map->add_obj(ship);
}

GameMap* QtUIFactory::get_game_map() {
    return game_map;
}

Mario* QtUIFactory::get_mario() {
    return mario;
}

// -----------------------------------------------------------------------------
// PRIVATE
// -----------------------------------------------------------------------------

void QtUIFactory::create_game_map() {
    game_map = new QtGameMap(30, 200);
}

} // namespace biv
