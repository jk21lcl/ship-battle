#include "defense_ship.h"
#include "game.h"

DefenseShip::DefenseShip(Game* game) : Ship(game)
{
    health_ = 15;
    max_health_ = 15;
    ship_type_ = defense_ship;
    name_ = "Defense Ship";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new Cannon2(game));
    cannons_.push_back(new Cannon3(game));
    skills_.push_back(new Shield(game));
}

void DefenseShip::Ban()
{
    if (health_ < 5)
        cannons_[2]->Ban();
    if (health_ < 3)
        cannons_[1]->Ban();
}

void DefenseShip::DecreaseHealth(double n, Ship* source)
{
    if (source && source->IsSuck())
        source->IncreaseHealth(n * 0.5);
    if (shield_health_)
        shield_health_ -= n;
    else
    {
        if (health_ >= 12)
            n -= 2;
        else
            n -= 1;
        if (n > 0)
            health_ -= n;
    }
    if (shield_health_ <= 0)
        shield_health_ = 0;
    if (health_ <= 0)
    {
        health_ = 0;
        alive_ = false;
    }
    Ban();
}