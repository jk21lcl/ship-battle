#include "sacrifice.h"
#include "game.h"

Sacrifice::Sacrifice(Game* game) : Skill(game)
{
    skill_type_ = sacrifice;
    name_ = "Sacrifice";
    target_type_ = enemy;
    skill_property_ = attack_skill;
    max_cd_ = 0;
}

void Sacrifice::Use(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    OutputCrit(source, target);
    if (!ProcessDodge(source, target))
        target->DecreaseHealth(2 * crit_, source);
    source->DecreaseHealth(2, nullptr);
}