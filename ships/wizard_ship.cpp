#include "wizard_ship.h"
#include "game.h"

WizardShip::WizardShip(Game* game, int id, Player* player) : Ship(game, id, player)
{
    health_ = 15;
    max_health_ = 15;
    can_stunned_ = false;
    shield_rebound_ = 100;
    ship_type_ = wizard_ship;
    name_ = "Wizard Ship";
    cannons_.push_back(new SplitCannon(game));
    cannons_.push_back(new SplitCannon(game));
    cannons_.push_back(new StunningCannon(game));
    cannons_.push_back(new ExplosiveCannon(game));
    skills_.push_back(new Immune(game));
    effects_.push_back(EffectInfo{shield_eff, 5});
}