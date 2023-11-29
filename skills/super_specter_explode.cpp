#include "super_specter_explode.h"
#include "game.h"

SuperSpecterExplode::SuperSpecterExplode(Game* game) : Skill(game)
{
    skill_type_ = super_specter_explode;
    name_ = "Super Specter Explode";
    max_cd_ = 0;
    target_type_ = enemy;
    skill_property_ = attack_skill;
}

void SuperSpecterExplode::Use(Ship* source, Ship* target)
{
    SpecterShip* specter_ship = dynamic_cast<SpecterShip*>(source);
    ProcessCrit(source, target);
    OutputCrit(source, target);
    if (!ProcessDodge(source, target))
    {
        double damage = specter_ship->GetSpecter() * 3 + 5;
        double splash_damage = specter_ship->GetSpecter() * 0.1 * damage;
        target->DecreaseHealth(damage * crit_, source);
        int id = target->GetId();
        vector<Ship*> ships = game_->GetOtherPlayer()->GetShips();
        int num = game_->GetOtherPlayer()->GetNum();
        if (id != 1)
        {
            ships[id - 2]->DecreaseHealth(splash_damage * crit_, source);
            OutputCrit(source, ships[id - 2]);
        }
        if (id != num)
        {
            ships[id]->DecreaseHealth(splash_damage * crit_, source);
            OutputCrit(source, ships[id]);
        }
    }
    specter_ship->IncreaseSpecter(-specter_ship->GetSpecter());
    Ban();
}