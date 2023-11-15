#include "wizard_ship.h"
#include "game.h"

WizardShip::WizardShip(Game* game, int id) : Ship(game, id)
{
    health_ = 15;
    max_health_ = 15;
    shield_health_ = 5;
    can_stunned_ = false;
    ship_type_ = wizard_ship;
    name_ = "Wizard Ship";
    cannons_.push_back(new SplitCannon(game));
    cannons_.push_back(new SplitCannon(game));
    cannons_.push_back(new StunningCannon(game));
    cannons_.push_back(new ExplosiveCannon(game));
    skills_.push_back(new Immune(game));
}

void WizardShip::Ban()
{
    if (health_ < 4)
        cannons_[2]->Ban();
    if (health_ < 8)
        cannons_[3]->Ban();
}

void WizardShip::DecreaseHealth(double n, Ship* source)
{
    if (shield_health_)
    {
        shield_health_ -= n;
        if (source)
            source->DecreaseHealth(n, nullptr);
    }
    else
        health_ -= n;
    if (source && source->IsSuck())
        source->IncreaseHealth(n);
    if (shield_health_ <= 0)
        shield_health_ = 0;
    if (health_ <= 0)
    {
        health_ = 0;
        alive_ = false;
    }
    Ban();
}