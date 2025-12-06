#pragma once

#include "console_box.hpp"
#include "console_enemy.hpp"
#include "console_flying_enemy.hpp"
#include "console_jumping_enemy.hpp"
#include "console_full_box.hpp"
#include "console_game_map.hpp"
#include "console_mario.hpp"
#include "console_money.hpp"
#include "console_ship.hpp"
#include "ui_factory.hpp"

namespace biv {
	class ConsoleUIFactory : public UIFactory {
		private:
			ConsoleGameMap* game_map = nullptr;
			std::vector<ConsoleBox*> boxes;
			std::vector<ConsoleFullBox*> full_boxes;
			std::vector<ConsoleShip*> ships;
			ConsoleMario* mario = nullptr;
			std::vector<ConsoleEnemy*> enemies;
			std::vector<ConsoleFlyingEnemy*> flying_enemies;
			std::vector<ConsoleJumpingEnemy*> jumping_enemies;
			std::vector<ConsoleMoney*> moneys;

		public:
			ConsoleUIFactory(Game* game);
			
			void clear_data() override;
			void create_box(
				const Coord& top_left, const int width, const int height
			) override;
			void create_enemy(
				const Coord& top_left, const int width, const int height
			) override;
			void create_flying_enemy(
                const Coord& top_left, const int width, const int height,
				const float left_bound, const float right_bound
            ) override;
            void create_jumping_enemy(
                    const Coord& top_left, const int width, const int height
            ) override;
			void create_full_box(
				const Coord& top_left, const int width, const int height
			) override;
			void create_mario(
				const Coord& top_left, const int width, const int height
			) override;
			void create_money(
				const Coord& top_left, const int width, const int height
			) override;
			void create_ship(
				const Coord& top_left, const int width, const int height
			) override;
			GameMap* get_game_map() override;
			Mario* get_mario() override;
			
		private:
			virtual void create_game_map() override;
	};
}
