#include "specter.h"
#include "game.h"

Specter::Specter(Game* game) : Skill(game)
{
    attack_times_ = 0;
    skill_type_ = specter;
    name_ = "Specter";
    max_cd_ = 3;
}

void Specter::Use(Ship* source, Ship* target)
{
    source->IncreaseEffect(specter_eff, 2);
}