#include "specter_ship.h"
#include "game.h"

SpecterShip::SpecterShip(Game* game, int id, Player* player) : Ship(game, id, player)
{
    health_ = 15;
    max_health_ = 15;
    ship_type_ = specter_ship;
    name_ = "Specter Ship";
    cannons_.push_back(new SpecterCannon(game_));
    cannons_.push_back(new SpecterCannon(game_));
    skills_.push_back(new Specter(game_));
    skills_.push_back(new Hide(game_));
    skills_.push_back(new SpecterExplode(game_));
    skills_.push_back(new SuperSpecterExplode(game_));
}

void SpecterShip::Update()
{
    dodge_prob_ = 10 * FindEffect(specter_eff);
    ratio_damage_reduce_ = 10 * FindEffect(specter_eff);
}