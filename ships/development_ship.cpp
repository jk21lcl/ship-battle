#include "development_ship.h"
#include "game.h"

DevelopmentShip::DevelopmentShip(Game* game, int id, Player* player) : Ship(game, id, player)
{
    health_ = 10;
    max_health_ = 10;
    crit_prob_ = 0;
    ship_type_ = development_ship;
    name_ = "Development Ship";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new Cannon2(game));
    cannons_.push_back(new Cannon3(game));
}

int DevelopmentShip::GetCritProb() const 
{
    return crit_prob_;
}

void DevelopmentShip::RandomUpdate()
{
    bool crit_update = (crit_prob_ != 50);
    bool dodge_update = (dodge_prob_ != 50);
    bool damage_reduce_update = (ratio_damage_reduce_ != 50);
    if (!crit_update && !dodge_update && !damage_reduce_update)
        return;
    while (true)
    {
        int random = rand() % 3;
        if (random == 0)
        {
            if (!crit_update)
                continue;
            crit_prob_ += 10;
            cout << GetId() << " \033[1;36m" << GetName() << "\033[0m";
            cout << " updates Crit Prob." << endl;
            return;
        }
        if (random == 1)
        {
            if (!dodge_update)
                continue;
            dodge_prob_ += 10;
            cout << GetId() << " \033[1;36m" << GetName() << "\033[0m";
            cout << " updates Dodge Prob." << endl;
            return;
        }
        if (random == 2)
        {
            if (!damage_reduce_update)
                continue;
            ratio_damage_reduce_ += 10;
            cout << GetId() << " \033[1;36m" << GetName() << "\033[0m";
            cout << " updates Damage Reduce." << endl;
            return;
        }
    }
}