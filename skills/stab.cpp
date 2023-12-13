#include "stab.h"
#include "game.h"

Stab::Stab(Game* game) : Skill(game)
{
    skill_type_ = stab;
    name_ = "Stab";
    target_type_ = enemy;
    skill_property_ = attack_skill;
    max_cd_ = 0;
}

void Stab::Use(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    OutputCrit(source, target);
    StabInfo stab_info = {source, target};
    game_->AddStabInfo(stab_info);
    if (!ProcessDodge(source, target))
    {
        int damage = rand() % 11 + 5;
        cout << source->GetId() << " \033[1;36m" << source->GetName() << "\033[0m";
        cout << "'s " << "\033[0;33m" << name_ << "\033[0m";
        cout << " makes " << damage << " base damage to ";
        cout << target->GetId() << " \033[1;36m" << target->GetName() << "\033[0m";
        cout << endl;
        target->DecreaseHealth(damage * crit_, source);
    }
}