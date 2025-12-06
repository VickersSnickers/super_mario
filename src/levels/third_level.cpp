#include "third_level.hpp"

using biv::ThirdLevel;

ThirdLevel::ThirdLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
    init_data();
}

bool ThirdLevel::is_final() const noexcept {
    return true;
}

biv::GameLevel* ThirdLevel::get_next() {
    return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void ThirdLevel::init_data() {
    ui_factory->create_mario({35, 10}, 3, 3);

    ui_factory->create_ship({10, 25}, 30, 2);
    ui_factory->create_ship({50, 20}, 20, 7);
    ui_factory->create_ship({80, 15}, 20, 3);
    ui_factory->create_ship({80, 25}, 20, 2);
    ui_factory->create_ship({110, 25}, 5, 2);
    ui_factory->create_ship({120, 25}, 5, 2);
    ui_factory->create_ship({130, 25}, 10, 2);
    ui_factory->create_full_box({100, 8}, 5, 3);
    ui_factory->create_ship({110, 18}, 25, 2);
    ui_factory->create_full_box({135, 10}, 5, 3);
    ui_factory->create_ship({140, 22}, 20, 2);
    ui_factory->create_ship({180, 17}, 15, 7);

    ui_factory->create_enemy({20, 23}, 3, 2);
    ui_factory->create_enemy({60, 18}, 3, 2);
    ui_factory->create_enemy({155, 20}, 3, 2);

    ui_factory->create_jumping_enemy({95, 12}, 3, 2);
    ui_factory->create_jumping_enemy({175, 22}, 3, 2);

    static constexpr float flying_left_1 = 40.0f;
    static constexpr float flying_right_1 = 90.0f;
    ui_factory->create_flying_enemy({70, 10}, 3, 2, flying_left_1, flying_right_1);

    static constexpr float flying_left_2 = 130.0f;
    static constexpr float flying_right_2 = 190.0f;
    ui_factory->create_flying_enemy({145, 9}, 3, 2, flying_left_2, flying_right_2);
}