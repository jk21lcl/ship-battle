#include "small_ship.h"
#include "game.h"

SmallShip::SmallShip(Game* game) : Ship(game)
{
    health_ = 5;
    ship_type_ = small_ship;
}