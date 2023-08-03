cmake_minimum_required(VERSION 3.9.1)

project(ShipBattle)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}"
                    "${CMAKE_CURRENT_SOURCE_DIR}/ships"
                    "${CMAKE_CURRENT_SOURCE_DIR}/cannons")

add_library(ship_battle game.cpp player.cpp object.cpp ship.cpp cannon.cpp
            ships/small_ship.cpp ships/middle_ship.cpp ships/big_ship.cpp 
            cannons/cannon_1.cpp cannons/cannon_2.cpp cannons/cannon_3.cpp
            cannons/cannon_4.cpp cannons/cannon_5.cpp)

add_executable(game_start main.cpp)
target_link_libraries(game_start ship_battle)