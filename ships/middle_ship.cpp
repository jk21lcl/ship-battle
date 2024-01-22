#include "middle_ship.h"
#include "game.h"

MiddleShip::MiddleShip(Game* game, int id, Player* player) : Ship(game, id, player)
{
    health_ = 10;
    max_health_ = 10;
    ship_type_ = middle_ship;
    name_ = "Middle Ship";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new Cannon2(game));
    cannons_.push_back(new Cannon3(game));
}