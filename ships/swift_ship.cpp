#include "swift_ship.h"
#include "game.h"

SwiftShip::SwiftShip(Game* game, int id) : Ship(game, id)
{
    health_ = 15;
    max_health_ = 15;
    dodge_prob_ = 25;
    ship_type_ = swift_ship;
    name_ = "Swift Ship";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new Cannon2(game));
    cannons_.push_back(new Cannon3(game));
    skills_.push_back(new Dodge(game));
}