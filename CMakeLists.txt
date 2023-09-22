cmake_minimum_required(VERSION 3.9.1)

project(ShipBattle)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}"
                    "${CMAKE_CURRENT_SOURCE_DIR}/ships"
                    "${CMAKE_CURRENT_SOURCE_DIR}/cannons"
                    "${CMAKE_CURRENT_SOURCE_DIR}/skills"
                    "${CMAKE_CURRENT_SOURCE_DIR}/events")

add_library(ship_battle game.cpp player.cpp object.cpp ship.cpp cannon.cpp skill.cpp
            event.cpp
            
            ships/small_ship.cpp ships/middle_ship.cpp ships/big_ship.cpp 
            ships/defense_ship.cpp ships/wizard_ship.cpp ships/heal_ship.cpp
            ships/crit_ship.cpp ships/swift_ship.cpp

            cannons/cannon_1.cpp cannons/cannon_2.cpp cannons/cannon_3.cpp
            cannons/cannon_4.cpp cannons/cannon_5.cpp
            cannons/split_cannon.cpp cannons/stunning_cannon.cpp
            cannons/explosive_cannon.cpp cannons/heal_cannon.cpp
            cannons/crit_cannon.cpp cannons/super_crit_cannon.cpp
            
            skills/shield.cpp skills/immune.cpp skills/suck.cpp skills/heal.cpp
            skills/super_heal.cpp skills/fury.cpp skills/dodge.cpp
            skills/super_shield.cpp
            
            events/cannon_event.cpp events/skill_event.cpp events/explosive_event.cpp)

add_executable(game_start main.cpp)
target_link_libraries(game_start ship_battle)