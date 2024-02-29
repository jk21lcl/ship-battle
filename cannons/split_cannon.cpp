#include "split_cannon.h"
#include "game.h"

SplitCannon::SplitCannon(Game* game) : Cannon(game)
{
    cannon_type_ = split_cannon;
    name_ = "Split Cannon";
    max_cd_ = 2;
    attack_times_ = 3;
    crit_count_ = 0;
}

void SplitCannon::ProcessCrit(Ship* source, Ship* target)
{
    if (source->FindEffect(fury_eff))
    {
        crit_ = 2;
        if (crit_count_ == 2)
        {
            source->DecreaseEffect(fury_eff, 1);
            crit_count_ = 0;
        }
        else
            crit_count_++;
    }
    else
        crit_ = 1;
}

void SplitCannon::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    OutputCrit(source, target);
    if (!ProcessDodge(source, target))
        target->DecreaseHealth(1 * crit_, source);
}