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
    SpecterShip* specter_ship = dynamic_cast<SpecterShip*>(source);
    specter_ship->IncreaseSpecter(2);
}