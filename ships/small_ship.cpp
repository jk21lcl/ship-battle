#include "small_ship.h"
#include "game.h"

SmallShip::SmallShip(Game* game) : Ship(game)
{
    health_ = 5;
    ship_type_ = small_ship;
    name_ = "SmallShip";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new Cannon2(game));
}

void SmallShip::Ban()
{
    if (health_ < 3)
        cannons_[1]->Ban();
}