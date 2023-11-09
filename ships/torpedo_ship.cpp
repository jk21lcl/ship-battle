#include "torpedo_ship.h"
#include "game.h"

TorpedoShip::TorpedoShip(Game* game, int id) : Ship(game, id)
{
    health_ = 15;
    max_health_ = 15;
    ship_type_ = torpedo_ship;
    name_ = "Torpedo Ship";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new Torpedo(game));
    cannons_.push_back(new Torpedo(game));
}