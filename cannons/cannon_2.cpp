#include "cannon_2.h"
#include "game.h"

Cannon2::Cannon2(Game* game) : Cannon(game)
{
    cannon_type_ = cannon_2;
    name_ = "Cannon2";
    max_cd_ = 2;
    ban_health_ = 3;
}

void Cannon2::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    if (!ProcessDodge(source, target))
    {
        if (!target->HasShield() && !target->IsImmune() && target->GetCanStunned())
        {
            int random = rand() % 100;
            if (random < 50)
            {
                target->IncreaseStun(1);
                cout << source->GetId() << " \033[1;36m" << source->GetName() << "\033[0m";
                cout << "'s " << "\033[0;33m" << "Cannon 2" << "\033[0m" <<" stuns ";
                cout << target->GetId() << " \033[1;36m" << target->GetName() << "\033[0m";
                cout << endl;
            }
        }
        target->DecreaseHealth(2 * crit_, source);
    }
}