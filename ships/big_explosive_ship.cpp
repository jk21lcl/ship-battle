#include "big_explosive_ship.h"
#include "game.h"

BigExplosiveShip::BigExplosiveShip(Game* game, int id) : Ship(game, id)
{
    health_ = 15;
    max_health_ = 15;
    can_stunned_ = false;
    ship_type_ = big_explosive_ship;
    name_ = "Big Explosive Ship";
    skills_.push_back(new BigExplode(game));
}