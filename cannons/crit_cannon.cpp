#include "crit_cannon.h"
#include "game.h"

CritCannon::CritCannon(Game* game) : Cannon(game)
{
    cannon_type_ = crit_cannon;
    name_ = "Crit Cannon";
    max_cd_ = 2;
}

void CritCannon::ProcessCrit(Ship* source, Ship* target)
{
    if (source->FindEffect(fury_eff))
    {
        crit_ = 2;
        source->DecreaseEffect(fury_eff, 1);
    }
    else
    {
        int random = rand() % 100;
        if (random < 30)
            crit_ = 2;
        else
            crit_ = 1;
    }
}

void CritCannon::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    OutputCrit(source, target);
    if (!ProcessDodge(source, target))
        target->DecreaseHealth(2 * crit_, source);
}