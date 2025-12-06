#include "console_ui_factory.hpp"

using biv::ConsoleUIFactory;

ConsoleUIFactory::ConsoleUIFactory(Game* game) : UIFactory(game) {
	create_game_map();
}

void ConsoleUIFactory::clear_data() {
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

void ConsoleUIFactory::create_box(
	const Coord& top_left, const int width, const int height
) {
	ConsoleBox* box = new ConsoleBox(top_left, width, height);
	boxes.push_back(box);
	game->add_map_movable(box);
	game->add_static_obj(box);
	game_map->add_obj(box);
}

void ConsoleUIFactory::create_enemy(
	const Coord& top_left, const int width, const int height
) {
	ConsoleEnemy* enemy = new ConsoleEnemy(top_left, width, height);
	enemies.push_back(enemy);
	game->add_map_movable(enemy);
	game->add_movable(enemy);
	game->add_collisionable(enemy);
	game_map->add_obj(enemy);
}

void ConsoleUIFactory::create_flying_enemy(
    const Coord& top_left, const int width, const int height,
	const float left_bound, const float right_bound
) {
    ConsoleFlyingEnemy* flying_enemy = new ConsoleFlyingEnemy(
		top_left, width, height, left_bound, right_bound);
    flying_enemies.push_back(flying_enemy);
    game->add_map_movable(flying_enemy);
    game->add_movable(flying_enemy);
    game->add_collisionable(flying_enemy);
    game_map->add_obj(flying_enemy);
}

void ConsoleUIFactory::create_jumping_enemy(
    const Coord& top_left, const int width, const int height
) {
    ConsoleJumpingEnemy* jumping_enemy = new ConsoleJumpingEnemy(
            top_left, width, height);
    jumping_enemies.push_back(jumping_enemy);
    game->add_map_movable(jumping_enemy);
    game->add_movable(jumping_enemy);
    game->add_collisionable(jumping_enemy);
    game_map->add_obj(jumping_enemy);
}

void ConsoleUIFactory::create_full_box(
	const Coord& top_left, const int width, const int height
) {
	ConsoleFullBox* full_box = new ConsoleFullBox(top_left, width, height, this);
	full_boxes.push_back(full_box);
	game->add_collisionable(full_box);
	game->add_map_movable(full_box);
	game->add_static_obj(full_box);
	game_map->add_obj(full_box);
}

void ConsoleUIFactory::create_mario(
	const Coord& top_left, const int width, const int height
) {
	game->remove_collisionable(mario);
	game->remove_movable(mario);
	game->remove_mario();
	game_map->remove_obj(mario);
	delete mario;
	mario = nullptr;
	
	mario = new ConsoleMario(top_left, width, height);
	game->add_collisionable(mario);
	game->add_movable(mario);
	game->add_mario(mario);
	game_map->add_obj(mario);
}

void ConsoleUIFactory::create_money(
	const Coord& top_left, const int width, const int height
) {
	ConsoleMoney* money = new ConsoleMoney(top_left, width, height);
	moneys.push_back(money);
	game->add_map_movable(money);
	game->add_movable(money);
	game->add_collisionable(money);
	game_map->add_obj(money);
}

void ConsoleUIFactory::create_ship(
	const Coord& top_left, const int width, const int height
) {
	ConsoleShip* ship = new ConsoleShip(top_left, width, height);
	ships.push_back(ship);
	game->add_map_movable(ship);
	game->add_static_obj(ship);
	game_map->add_obj(ship);
}

biv::GameMap* ConsoleUIFactory::get_game_map() {
	return game_map;
}

biv::Mario* ConsoleUIFactory::get_mario() {
	return mario;
}

// ----------------------------------------------------------------------------
// 									PRIVATE
// ----------------------------------------------------------------------------
void ConsoleUIFactory::create_game_map() {
	game_map = new ConsoleGameMap(30, 200);
}
