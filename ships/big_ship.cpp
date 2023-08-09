#include "big_ship.h"
#include "game.h"

BigShip::BigShip(Game* game) : Ship(game)
{
    health_ = 20;
    max_health_ = 20;
    ship_type_ = big_ship;
    name_ = "Big Ship";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new Cannon2(game));
    cannons_.push_back(new Cannon3(game));
    cannons_.push_back(new Cannon4(game));
    cannons_.push_back(new Cannon5(game));
}

void BigShip::Ban()
{
    if (health_ < 15)
        cannons_[4]->Ban();
    if (health_ < 10)
        cannons_[3]->Ban();
    if (health_ < 5)
        cannons_[2]->Ban();
    if (health_ < 3)
        cannons_[1]->Ban();
}