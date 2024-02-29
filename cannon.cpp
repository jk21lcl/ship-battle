#include "cannon.h"
#include "game.h"

Cannon::Cannon(Game* game) : Object(game)
{
    object_type_ = cannon;
    available_ = true;
    ban_health_ = 0;
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

int Cannon::GetBanHealth() const
{
    return ban_health_;
}

bool Cannon::IsAvailable() const
{
    return available_;
}

bool Cannon::IsJustUsed() const
{
    return just_used_;
}

void Cannon::SetJustUsed(bool just_used)
{
    just_used_ = just_used;
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
    if (source->FindEffect(fury_eff))
    {
        crit_ = 2;
        source->DecreaseEffect(fury_eff, 1);
    }
    else if (source->GetShipType() == development_ship)
    {
        DevelopmentShip* development_ship = dynamic_cast<DevelopmentShip*>(source);
        int random = rand() % 100;
        if (random < development_ship->GetCritProb())
            crit_ = 2;
    }
    else
        crit_ = 1;
}

void Cannon::OutputCrit(Ship* source, Ship* target) const
{
    if (crit_ != 1)
    {
        cout << source->GetId() << " \033[1;36m" << source->GetName() << "\033[0m";
        cout << "'s " << "\033[0;33m" << name_ << "\033[0m";
        cout << " made a " << "\033[0;33m" << crit_ << "\033[0m" << " crit to ";
        if (target)
            cout << target->GetId() << " \033[1;36m" << target->GetName() << "\033[0m";
        else 
            cout << "the air";
        cout << endl;
    }
}

bool Cannon::ProcessDodge(Ship* source, Ship* target)
{
    if (target->FindEffect(lock_eff))
        dodge_ = 0;
    else if (target->FindEffect(hide_eff))
        dodge_ = 100;
    else 
    {
        dodge_ = target->GetDodgeProb();
        if (target->FindEffect(dodge_eff))
            dodge_ += 25;
    }
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