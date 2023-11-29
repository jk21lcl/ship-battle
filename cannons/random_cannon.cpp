#include "random_cannon.h"
#include "game.h"

RandomCannon::RandomCannon(Game* game) : Cannon(game)
{
    cannon_type_ = random_cannon;
    attack_times_ = 0;
    name_ = "Random Cannon";
    max_cd_ = 3;
}

void RandomCannon::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    vector<Ship*> ships = game_->GetOtherPlayer()->GetShips();
    int num = game_->GetOtherPlayer()->GetNum();
    
    // random choose number of targets
    int times = rand() % 3 + 1;
    for (int i = 0; i < times; i++)
    {
        // check whether there exists living ship
        bool alive = false;
        for (Ship* ship : ships)
            if (ship->IsAlive())
            {
                alive = true;
                break;
            }
        if (!alive)
            break;
        
        // random choose targets
        int id;
        while (true)
        {
            id = rand() % num;
            if (!ships[id]->IsAlive())
                continue;
            break;
        }

        // random choose damage
        int damage = rand() % 5 + 1;

        if (!ProcessDodge(source, ships[id]))
        {
            ships[id]->DecreaseHealth(damage * crit_, source);
            cout << source->GetId() << " \033[1;36m" << source->GetName() << "\033[0m";
            cout << "'s " << "\033[0;33m" << name_ << "\033[0m";
            cout << " makes " << damage << " base damage to ";
            cout << ships[id]->GetId() << " \033[1;36m" << ships[id]->GetName() << "\033[0m";
            cout << endl;
            OutputCrit(source, ships[id]);
        }
    }
}