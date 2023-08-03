#include "middle_ship.h"
#include "game.h"

MiddleShip::MiddleShip(Game* game) : Ship(game)
{
    health_ = 10;
    ship_type_ = middle_ship;
    name_ = "MiddleShip";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new Cannon2(game));
    cannons_.push_back(new Cannon3(game));
}