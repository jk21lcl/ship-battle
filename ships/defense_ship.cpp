#include "defense_ship.h"
#include "game.h"

DefenseShip::DefenseShip(Game* game, int id) : Ship(game, id)
{
    health_ = 15;
    max_health_ = 15;
    ship_type_ = defense_ship;
    name_ = "Defense Ship";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new Cannon2(game));
    cannons_.push_back(new Cannon3(game));
    skills_.push_back(new Shield(game));
    skills_.push_back(new SuperShield(game));
    Update();
}

void DefenseShip::Update()
{
    if (health_ >= 12)
        absolute_damage_reduce_ = 2;
    else 
        absolute_damage_reduce_ = 1;
}