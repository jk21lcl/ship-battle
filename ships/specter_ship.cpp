#include "specter_ship.h"
#include "game.h"

SpecterShip::SpecterShip(Game* game, int id, Player* player) : Ship(game, id, player)
{
    health_ = 15;
    max_health_ = 15;
    specter_ = 0;
    ship_type_ = specter_ship;
    name_ = "Specter Ship";
    cannons_.push_back(new SpecterCannon(game_));
    cannons_.push_back(new SpecterCannon(game_));
    skills_.push_back(new Specter(game_));
    skills_.push_back(new Hide(game_));
    skills_.push_back(new SpecterExplode(game_));
    skills_.push_back(new SuperSpecterExplode(game_));
}

int SpecterShip::GetSpecter() const
{
    return specter_;
}

bool SpecterShip::IsSpecter() const
{
    return specter_;
}

void SpecterShip::IncreaseSpecter(int n)
{
    specter_ = min(specter_ + n, 5);
    Update();
}

void SpecterShip::Update()
{
    dodge_prob_ = 10 * specter_;
    ratio_damage_reduce_ = 10 * specter_;
}