#include "bomb_ship.h"
#include "game.h"

BombShip::BombShip(Game* game, int id, Player* player) : Ship(game, id, player)
{
    health_ = 16;
    max_health_ = 16;
    attack_times_ = 2;
    ship_type_ = bomb_ship;
    name_ = "Bomb Ship";
    skills_.push_back(new TimeBomb(game));
    skills_.push_back(new UntimeBomb(game));
    skills_.push_back(new SmallBomb(game));
    skills_.push_back(new BigBomb(game));
}

void BombShip::Bomb()
{
    int random = rand() % 100;
    if (random < 15)
    {
        DecreaseHealth(8, nullptr);
        cout << id_ << " \033[1;36m" << name_ << "\033[0m";
        cout << " explodes." << endl;
    }
}