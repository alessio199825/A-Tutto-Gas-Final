cmake_minimum_required(VERSION 3.14)
project(A_Tutto_Gas)

set(CMAKE_CXX_STANDARD 14)

set(EXECUTABLE_NAME A_Tutto_Gas)
add_executable(EXECUTABLE_NAME CMakeLists.txt main.cpp Race.cpp Race.h Control.cpp Control.h Error.cpp Error.h Car.cpp Car.h Weather.cpp Weather.h Circuit.cpp Circuit.h Cars_Cpu.cpp Cars_Cpu.h Traffic_Light.cpp Traffic_Light.h Song.cpp Song.h Menu_State.cpp Menu_State.h Menu_Game.cpp Menu_Game.h Championship_Page.cpp Championship_Page.h SingleRace_Page.cpp SingleRace_Page.h SingleRace_Page2.cpp SingleRace_Page2.h Load_Page.cpp Load_Page.h TimeTrial_Page.cpp TimeTrial_Page.h Setting_Page.cpp Setting_Page.h State_Option.cpp State_Option.h Menu_Loop.cpp Menu_Loop.h LoadMenu_Page.cpp LoadMenu_Page.h Race_Page.cpp Race_Page.h fsa.h stlastar.h A_Star.cpp A_Star.h Tilemaps.cpp Tilemaps.h MapSearchNode.cpp MapSearchNode.h Flag_Page.cpp Flag_Page.h Collision.cpp Collision.h "BitmaskManager .h")
set(SOURCE_FILE main.cpp Race.cpp Race.h Control.cpp Control.h Error.cpp Error.h Car.cpp Car.h Weather.cpp Weather.h Circuit.cpp Circuit.h Cars_Cpu.cpp Cars_Cpu.h Traffic_Light.cpp Traffic_Light.h Song.cpp Song.h Menu_State.cpp Menu_State.h Menu_Game.cpp Menu_Game.h Championship_Page.cpp Championship_Page.h SingleRace_Page.cpp SingleRace_Page.h SingleRace_Page2.cpp SingleRace_Page2.h Load_Page.cpp Load_Page.h TimeTrial_Page.cpp TimeTrial_Page.h Setting_Page.cpp Setting_Page.h State_Option.cpp State_Option.h Menu_Loop.cpp Menu_Loop.h LoadMenu_Page.cpp LoadMenu_Page.h Race_Page.cpp Race_Page.h fsa.h stlastar.h A_Star.cpp A_Star.h Tilemaps.cpp Tilemaps.h MapSearchNode.cpp MapSearchNode.h Flag_Page.cpp Flag_Page.h Collision.cpp Collision.h "BitmaskManager .h")
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})

find_package(SFML 2 COMPONENTS system network graphics window audio REQUIRED)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(EXECUTABLE_NAME ${SFML_LIBRARIES})
endif ()

add_subdirectory(test)
add_library(core ${SOURCE_FILE})
target_link_libraries(EXECUTABLE_NAME core)