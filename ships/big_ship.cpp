#include "big_ship.h"
#include "game.h"

BigShip::BigShip(Game* game) : Ship(game)
{
    health_ = 20;
    ship_type_ = big_ship;
}