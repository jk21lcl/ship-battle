#include "blow.h"
#include "game.h"

Blow::Blow(Game* game) : Skill(game)
{
    skill_type_ = blow;
    name_ = "Blow";
    max_cd_ = 0;
    skill_property_ = attack_skill;
    target_type_ = enemy;
}

void Blow::Use(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    OutputCrit(source, target);
    if (!ProcessDodge(source, target))
    {
        target->DecreaseHealth(target->FindEffect(burn_eff) * crit_, source);
        target->IncreaseEffect(burn_eff, target->FindEffect(burn_eff));
    }
    Ban();
}