#include "middle_ship.h"
#include "game.h"

MiddleShip::MiddleShip(Game* game) : Ship(game)
{
    health_ = 10;
    ship_type_ = middle_ship;
}