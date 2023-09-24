#include "small_explosive_ship.h"
#include "game.h"

SmallExplosiveShip::SmallExplosiveShip(Game* game, int id) : Ship(game, id)
{
    health_ = 5;
    max_health_ = 5;
    ship_type_ = small_explosive_ship;
    name_ = "Small Explosive Ship";
    skills_.push_back(new SmallExplode(game));
}