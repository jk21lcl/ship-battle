#include "igniting_ship.h"
#include "game.h"

IgnitingShip::IgnitingShip(Game* game, int id, Player* player) : Ship(game, id, player)
{
    health_ = 20;
    max_health_ = 20;
    ship_type_ = igniting_ship;
    name_ = "Igniting Ship";
    cannons_.push_back(new BurningCannon(game));
    cannons_.push_back(new BurningCannon(game));
    skills_.push_back(new Ignite(game));
    skills_.push_back(new Blow(game));
}