#include "medium_explosive_ship.h"
#include "game.h"

MediumExplosiveShip::MediumExplosiveShip(Game* game, int id) : Ship(game, id)
{
    health_ = 10;
    max_health_ = 10;
    ship_type_ = medium_explosive_ship;
    name_ = "Medium Explosive Ship";
    skills_.push_back(new MediumExplode(game));
}