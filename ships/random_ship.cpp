#include "random_ship.h"
#include "game.h"

RandomShip::RandomShip(Game* game, int id, Player* player) : Ship(game, id, player)
{
    health_ = rand() % 10 + 11;
    max_health_ = health_;
    ship_type_ = random_ship;
    name_ = "Random Ship";
    cannons_.push_back(new BiasedCannon(game));
    cannons_.push_back(new RandomCannon(game));
    cannons_.push_back(new RandomHealCannon(game));
    skills_.push_back(new RandomBuff(game));
    effects_.push_back(EffectInfo{shield_eff, rand() % 5 + 1});
}