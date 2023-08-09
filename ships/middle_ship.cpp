#include "middle_ship.h"
#include "game.h"

MiddleShip::MiddleShip(Game* game) : Ship(game)
{
    health_ = 10;
    max_health_ = 10;
    ship_type_ = middle_ship;
    name_ = "Middle Ship";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new Cannon2(game));
    cannons_.push_back(new Cannon3(game));
}

void MiddleShip::Ban()
{
    if (health_ < 5)
        cannons_[2]->Ban();
    if (health_ < 3)
        cannons_[1]->Ban();
}