#include "second_level.hpp"
#include "third_level.hpp"

using biv::SecondLevel;

SecondLevel::SecondLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool SecondLevel::is_final() const noexcept {
	return false;
}

biv::GameLevel* SecondLevel::get_next() {
    if (!next) {
        clear_data();
        next = new biv::ThirdLevel(ui_factory);
    }
    return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void SecondLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);
	
	ui_factory->create_ship({20, 25}, 40, 2);
	ui_factory->create_ship({60, 20}, 10, 7);

	ui_factory->create_ship({80, 25}, 20, 2);
	ui_factory->create_ship({110, 25}, 10, 2);
	ui_factory->create_ship({80, 15}, 15, 3);
	ui_factory->create_full_box({95, 15}, 5, 3);
	ui_factory->create_ship({100, 15}, 10, 3);

	ui_factory->create_ship({120, 20}, 10, 7);
	ui_factory->create_ship({150, 25}, 10, 2);
	ui_factory->create_ship({170, 25}, 10, 2);
	ui_factory->create_ship({190, 25}, 10, 2);
	ui_factory->create_ship({210, 20}, 10, 7);

	ui_factory->create_enemy({80, 23}, 3, 2);
	ui_factory->create_enemy({55, 20}, 3, 2);
	ui_factory->create_enemy({80, 10}, 3, 2);
	ui_factory->create_jumping_enemy({118, 25}, 3, 2);
	static constexpr float fe1_start = 120.0f;
    static constexpr float fe1_end = 180.0f;
	ui_factory->create_flying_enemy({120, 15}, 3, 2, fe1_start, fe1_end);
	static constexpr float fe2_start = 150.0f;
    static constexpr float fe2_end = 200.0f;
	ui_factory->create_flying_enemy({150, 20}, 3, 2, fe2_start, fe2_end);
}
