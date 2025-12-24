target_sources(${PROJECT_NAME}
	PRIVATE
		qt_game_map.cpp
		qt_ui_obj.cpp
		qt_ui_factory.cpp
		qt_ui_obj_rect_adapter.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)

add_subdirectory(ui_objects)
