target_sources(${PROJECT_NAME}
	PRIVATE
		qt_box.cpp
		qt_enemy.cpp
		qt_flying_enemy.cpp
		qt_jumping_enemy.cpp
		qt_full_box.cpp
		qt_mario.cpp
		qt_money.cpp
		qt_ship.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)
