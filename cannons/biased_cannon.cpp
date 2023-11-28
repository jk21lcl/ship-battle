#include "cannon_1.h"
#include "game.h"

BiasedCannon::BiasedCannon(Game* game) : Cannon(game)
{
    cannon_type_ = biased_cannon;
    name_ = "Biased Cannon";
    max_cd_ = 2;
}

void BiasedCannon::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    if (!ProcessDodge(source, target))
    {
        int id = target->GetId();
        vector<Ship*> ships = game_->GetOtherPlayer()->GetShips();
        int num = game_->GetOtherPlayer()->GetNum();
        int random = rand() % 100;
        if (random < 50)
        {
            target->DecreaseHealth(3 * crit_, source);
            OutputTarget(source, target);
            OutputCrit(source, target);
        }
        else if (random < 75)
        {
            if (id != 1)
            {
                Ship* ship = ships[id - 2];
                ship->DecreaseHealth(3 * crit_, source);
                OutputTarget(source, ship);
                OutputCrit(source, ship);
            }
            else 
            {
                OutputTarget(source, nullptr);
                OutputCrit(source, nullptr);
            }
        }
        else 
        {
            if (id != num)
            {
                Ship* ship = ships[id];
                ship->DecreaseHealth(3 * crit_, source);
                OutputTarget(source, ship);
                OutputCrit(source, ship);
            }
            else 
            {
                OutputTarget(source, nullptr);
                OutputCrit(source, nullptr);
            }
        }
    }  
}

void BiasedCannon::OutputTarget(Ship* source, Ship* target) const
{
    cout << source->GetId() << " \033[1;36m" << source->GetName() << "\033[0m";
    cout << "'s " << "\033[0;33m" << name_ << "\033[0m";
    cout << " targets at ";
    if (target)
        cout << target->GetId() << " \033[1;36m" << target->GetName() << "\033[0m";
    else 
        cout << "the air";
    cout << endl;
}