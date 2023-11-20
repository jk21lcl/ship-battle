#include "torpedo.h"
#include "game.h"

Torpedo::Torpedo(Game* game) : Cannon(game)
{
    cannon_type_ = torpedo;
    name_ = "Torpedo";
    max_cd_ = 2;
}

void Torpedo::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    int random = rand() % 100;
    if (random < 30)
    {
        if (!ProcessDodge(source, target))
        {
            target->DecreaseHealth(8 * crit_, source);
            if (!target->IsImmune())
                target->IncreaseBurn(3);
        }
    }
    else
    {
        cout << source->GetId() << " \033[1;36m" << source->GetName() << "\033[0m";
        cout << "'s torpedo deviates from its route." << endl;
    }
}