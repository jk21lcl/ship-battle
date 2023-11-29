#include "wizard_ship.h"
#include "game.h"

WizardShip::WizardShip(Game* game, int id) : Ship(game, id)
{
    health_ = 15;
    max_health_ = 15;
    shield_health_ = 5;
    can_stunned_ = false;
    shield_rebound_ = 100;
    ship_type_ = wizard_ship;
    name_ = "Wizard Ship";
    cannons_.push_back(new SplitCannon(game));
    cannons_.push_back(new SplitCannon(game));
    cannons_.push_back(new StunningCannon(game));
    cannons_.push_back(new ExplosiveCannon(game));
    skills_.push_back(new Immune(game));
}