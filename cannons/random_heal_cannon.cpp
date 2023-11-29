#include "random_heal_cannon.h"
#include "game.h"

RandomHealCannon::RandomHealCannon(Game* game) : Cannon(game)
{
    cannon_type_ = random_heal_cannon;
    target_type_ = ally;
    name_ = "Random Heal Cannon";
    max_cd_ = 2;
}

void RandomHealCannon::Attack(Ship* source, Ship* target)
{
    int heal = rand() % 5 + 1;
    target->IncreaseHealth(heal);
    cout << source->GetId() << " \033[1;36m" << source->GetName() << "\033[0m";
    cout << "'s " << "\033[0;33m" << name_ << "\033[0m";
    cout << " adds " << heal << " health to ";
    cout << target->GetId() << " \033[1;36m" << target->GetName() << "\033[0m";
    cout << endl;
}