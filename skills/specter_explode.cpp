#include "specter_explode.h"
#include "game.h"

SpecterExplode::SpecterExplode(Game* game) : Skill(game)
{
    skill_type_ = specter_explode;
    name_ = "Specter Explode";
    max_cd_ = 3;
    target_type_ = enemy;
    skill_property_ = attack_skill;
}

void SpecterExplode::Use(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    OutputCrit(source, target);
    if (!ProcessDodge(source, target))
        target->DecreaseHealth((source->FindEffect(specter_eff) + 2) * crit_, source);
    source->DeleteEffect(specter_eff);
}