/**
	Игровой цикл - это обощённое представление потока событий, происходящих в игре.

	Игровой цикл:
		1. Установка параметров игры
		2. Получение пользовательского ввода
		3. Обновление внутреннего состояния игры
		4. Обновление изображения на экране
		5. Проверка того, не окончена ли игра

		*** Если игра не окончена, то возвращаемся в пункт № 2.

		6. Завершение
*/

#include <memory>

#include <QApplication>
#include <QTimer>

#include "first_level.hpp"
#include "game.hpp"
#include "game_level.hpp"
#include "mario.hpp"
#include "qt_game_map.hpp"
#include "qt_game_window.hpp"
#include "qt_ui_factory.hpp"

int main(int argc, char* argv[]) {
	// 1. Установка параметров игры
	QApplication app(argc, argv);
	biv::Game game;
	biv::QtUIFactory ui_factory(&game);
	auto* game_map = static_cast<biv::QtGameMap*>(ui_factory.get_game_map());
	std::unique_ptr<biv::GameLevel> game_level = std::make_unique<biv::FirstLevel>(&ui_factory);
	biv::Mario* mario = ui_factory.get_mario();
	QtGameWindow window(game_map);
	window.show();
	window.position_camera_on_mario(mario);

	QTimer timer;
	QObject::connect(&timer, &QTimer::timeout, [&]() {
		if (game.is_finished()) {
			app.quit();
			return;
		}

		// 2. Получение пользовательского ввода
		if (window.take_exit_requested()) {
			game.finish();
			app.quit();
			return;
		}
		if (window.take_jump_requested()) {
			mario->jump();
		}
		if (window.is_move_left() && !window.is_move_right()) {
			mario->move_map_right();
			if (!game.check_static_collisions(mario)) {
				game.move_map_right();
			}
			mario->move_map_left();
		} else if (window.is_move_right() && !window.is_move_left()) {
			mario->move_map_left();
			if (!game.check_static_collisions(mario)) {
				game.move_map_left();
			}
			mario->move_map_right();
		}

		// 3. Обновление внутреннего состояния игры
		game.move_objs_horizontally();
		game.check_horizontally_static_collisions();

		game.move_objs_vertically();
		game.check_mario_collision();
		game.check_vertically_static_collisions();

		if (game_map->is_below_map(mario->get_top()) || !mario->is_active()) {
			game_level->restart();
			mario = ui_factory.get_mario();
			window.position_camera_on_mario(mario);
		}

		if (game.is_level_end()) {
			if (!game_level->is_final()) {
				game_level.reset(game_level->get_next());

				mario = ui_factory.get_mario();
				game.start_level();
				window.position_camera_on_mario(mario);
			} else {
				game.finish();
				app.quit();
				return;
			}
		}

		// 4. Обновление изображения на экране
		game_map->refresh();
	});
	timer.start(10);

	return app.exec();
}