#include "cannon.h"
#include "game.h"

Cannon::Cannon(Game* game) : Object(game)
{
    object_type_ = cannon;
    available_ = true;
    cd_ = 0;
    crit_ = 1;
    dodge_ = 0;
    target_type_ = enemy;
    attack_times_ = 1;
}

void Cannon::SetCd(int cd)
{
    cd_ = cd;
}

int Cannon::GetCd() const
{
    return cd_;
}

int Cannon::GetMaxCd() const
{
    return max_cd_;
}

bool Cannon::IsReady() const
{
    return cd_ == 0;
}

bool Cannon::IsAvailable() const
{
    return available_;
}

void Cannon::Ban()
{
    available_ = false;
}

CannonType Cannon::GetCannonType() const
{
    return cannon_type_;
}

TargetType Cannon::GetTargetType() const
{
    return target_type_;
}

int Cannon::GetAttackTimes() const
{
    return attack_times_;
}

void Cannon::ProcessCrit(Ship* source, Ship* target)
{
    if (source->IsFury())
    {
        crit_ = 2;
        source->IncreaseFury(-1);
    }
    else
        crit_ = 1;
    OutputCrit(source, target);
}

void Cannon::OutputCrit(Ship* source, Ship* target) const
{
    if (crit_ != 1)
    {
        cout << source->GetId() << " \033[1;36m" << source->GetName() << "\033[0m";
        cout << "'s " << "\033[0;33m" << name_ << "\033[0m";
        cout << " made a " << "\033[0;33m" << crit_ << "\033[0m" << " crit to ";
        cout << target->GetId() << " \033[1;36m" << target->GetName() << "\033[0m";
        cout << endl;
    }
}

bool Cannon::ProcessDodge(Ship* source, Ship* target)
{
    dodge_ = 0;
    if (target->GetShipType() == swift_ship)
        dodge_ += 25;
    if (target->IsDodge())
        dodge_ += 25;
    int random = rand() % 100;
    if (random < dodge_)
    {
        cout << source->GetId() << " \033[1;36m" << source->GetName() << "\033[0m";
        cout << "'s " << "\033[0;33m" << name_ << "\033[0m" << " is dodged by ";
        cout << target->GetId() << " \033[1;36m" << target->GetName() << "\033[0m";
        cout << endl;
        return true;
    }
    return false;
}