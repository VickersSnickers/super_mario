#include "qt_ui_factory.hpp"

using biv::QtUIFactory;

QtUIFactory::QtUIFactory(Game* game)
    : UIFactory(game) {
    create_game_map();
}

void QtUIFactory::clear_data() {
    game->remove_objs();
    game_map->remove_objs();

    delete mario;
    mario = nullptr;

    boxes.clear();
    full_boxes.clear();
    ships.clear();
    enemies.clear();
    flying_enemies.clear();
    jumping_enemies.clear();
    moneys.clear();
}

void QtUIFactory::create_box(const Coord&, int, int) {
    auto* box = new QtBox(*game->get_last_created_box());
    boxes.push_back(box);

    game->add_map_movable(box);
    game->add_static_obj(box);
    game_map->add_obj(box);
}

void QtUIFactory::create_enemy(const Coord&, int, int) {
    auto* enemy = new QtEnemy(*game->get_last_created_enemy());
    enemies.push_back(enemy);

    game->add_map_movable(enemy);
    game->add_movable(enemy);
    game->add_collisionable(enemy);
    game_map->add_obj(enemy);
}

void QtUIFactory::create_flying_enemy(const Coord&, int, int, float, float) {
    auto* enemy = new QtFlyingEnemy(*game->get_last_created_flying_enemy());
    flying_enemies.push_back(enemy);

    game->add_map_movable(enemy);
    game->add_movable(enemy);
    game->add_collisionable(enemy);
    game_map->add_obj(enemy);
}

void QtUIFactory::create_jumping_enemy(const Coord&, int, int) {
    auto* enemy = new QtJumpingEnemy(*game->get_last_created_jumping_enemy());
    jumping_enemies.push_back(enemy);

    game->add_map_movable(enemy);
    game->add_movable(enemy);
    game->add_collisionable(enemy);
    game_map->add_obj(enemy);
}

void QtUIFactory::create_full_box(const Coord&, int, int) {
    auto* box = new QtFullBox(*game->get_last_created_full_box());
    full_boxes.push_back(box);

    game->add_collisionable(box);
    game->add_map_movable(box);
    game->add_static_obj(box);
    game_map->add_obj(box);
}

void QtUIFactory::create_mario(const Coord&, int, int) {
    if (mario) {
        game->remove_collisionable(mario);
        game->remove_movable(mario);
        game->remove_mario();
        game_map->remove_obj(mario);
        delete mario;
    }

    mario = new QtMario(*game->get_last_created_mario());

    game->add_collisionable(mario);
    game->add_movable(mario);
    game->add_mario(mario);
    game_map->add_obj(mario);
}

void QtUIFactory::create_money(const Coord&, int, int) {
    auto* money = new QtMoney(*game->get_last_created_money());
    moneys.push_back(money);

    game->add_map_movable(money);
    game->add_movable(money);
    game->add_collisionable(money);
    game_map->add_obj(money);
}

void QtUIFactory::create_ship(const Coord&, int, int) {
    auto* ship = new QtShip(*game->get_last_created_ship());
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
