#include "heal_ship.h"
#include "game.h"

HealShip::HealShip(Game* game, int id, Player* player) : Ship(game, id, player)
{
    health_ = 30;
    max_health_ = 30;
    heal_health_ = 2;
    ship_type_ = heal_ship;
    name_ = "Heal Ship";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new HealCannon(game));
    skills_.push_back(new Suck(game));
    skills_.push_back(new Heal(game));
    skills_.push_back(new SuperHeal(game));
}