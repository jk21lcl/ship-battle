#include "cannon_2.h"
#include "game.h"

Cannon2::Cannon2(Game* game) : Cannon(game)
{
    cannon_type_ = cannon_2;
    name_ = "Cannon2";
}

void Cannon2::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    if (!ProcessDodge(source, target))
    {
        if (!target->HasShield() && !target->IsImmune())
        {
            ShipType type = target->GetShipType();
            if (type != wizard_ship && type != small_explosive_ship && 
                type != medium_explosive_ship && type != big_explosive_ship)
            {
                int random = rand() % 100;
                if (random < 50)
                {
                    target->IncreaseStun(1);
                    cout << source->GetId() << " \033[1;36m" << source->GetName() << "\033[0m";
                    cout << " stuns ";
                    cout << target->GetId() << " \033[1;36m" << target->GetName() << "\033[0m";
                    cout << endl;
                }
            }
        }
        target->DecreaseHealth(2 * crit_, source);
    }
    cd_ = 3;
}