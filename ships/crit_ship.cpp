#include "crit_ship.h"
#include "game.h"

CritShip::CritShip(Game* game, int id) : Ship(game, id)
{
    health_ = 15;
    max_health_ = 15;
    ship_type_ = crit_ship;
    name_ = "Crit Ship";
    cannons_.push_back(new CritCannon(game));
    cannons_.push_back(new CritCannon(game));
    cannons_.push_back(new SuperCritCannon(game));
    skills_.push_back(new Fury(game));
}