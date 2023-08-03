#include "big_ship.h"
#include "game.h"

BigShip::BigShip(Game* game) : Ship(game)
{
    health_ = 20;
    ship_type_ = big_ship;
    name_ = "BigShip";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new Cannon2(game));
    cannons_.push_back(new Cannon3(game));
    cannons_.push_back(new Cannon4(game));
    cannons_.push_back(new Cannon5(game));
}