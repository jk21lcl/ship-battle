#include "shield.h"
#include "game.h"

RandomBuff::RandomBuff(Game* game) : Skill(game)
{
    skill_type_ = random_buff;
    name_ = "Random Buff";
    max_cd_ = 2;
}

void RandomBuff::Use(Ship* source, Ship* target)
{
    int type = rand() % 9;
    cout << source->GetId() << " \033[1;36m" << source->GetName() << "\033[0m";
    cout << "'s " << "\033[0;33m" << name_ << "\033[0m";
    cout << " adds 2 layers of ";
    switch (type)
    {
        case 0: // shield
            target->IncreaseShieldHealth(2);
            cout << "\033[0;32m" << "shield" << "\033[0m";
            break;
        case 1: // immune
            target->IncreaseImmune(2);
            cout << "\033[1;35m" << "immune" << "\033[0m";
            break;
        case 2: // suck
            target->IncreaseSuck(2);
            cout << "\033[0;35m" << "suck" << "\033[0m";
            break;
        case 3: // heal
            target->IncreaseHeal(2);
            cout << "\033[1;32m" << "heal" << "\033[0m";
            break;
        case 4: // fury
            target->IncreaseFury(2);
            cout << "\033[0;33m" << "fury" << "\033[0m";
            break;
        case 5: // dodge
            target->IncreaseDodge(2);
            cout << "\033[1;34m" << "dodge" << "\033[0m";
            break;
        case 6: // hide
            target->IncreaseHide(2);
            cout << "\033[1;35m" << "hide" << "\033[0m";
            break;
        case 7: // stun
            target->IncreaseStun(2);
            cout << "\033[1;33m" << "stun" << "\033[0m";
            break;
        case 8: // burn
            target->IncreaseBurn(2);
            cout << "\033[0;31m" << "burn" << "\033[0m";
            break;
    }
    cout << " to ";
    cout << target->GetId() << " \033[1;36m" << target->GetName() << "\033[0m";
    cout << endl;
}