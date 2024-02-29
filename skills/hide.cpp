#include "hide.h"
#include "game.h"

Hide::Hide(Game* game) : Skill(game)
{
    skill_type_ = hide;
    name_ = "Hide";
    max_cd_ = 0;
    attack_times_ = 0;
}

void Hide::Use(Ship* source, Ship* target)
{
    if (source->FindEffect(specter_eff))
    {
        source->IncreaseEffect(hide_eff, 1);
        source->DecreaseEffect(specter_eff, 1);
    }
}