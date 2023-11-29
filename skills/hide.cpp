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
    SpecterShip* specter_ship = dynamic_cast<SpecterShip*>(source);
    if (specter_ship->IsSpecter())
    {
        specter_ship->IncreaseHide(1);
        specter_ship->IncreaseSpecter(-1);
    }
}