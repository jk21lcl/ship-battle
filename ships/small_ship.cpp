#include "small_ship.h"
#include "game.h"

SmallShip::SmallShip(Game* game, int id, Player* player) : Ship(game, id, player)
{
    health_ = 5;
    max_health_ = 5;
    ship_type_ = small_ship;
    name_ = "Small Ship";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new Cannon2(game));
}