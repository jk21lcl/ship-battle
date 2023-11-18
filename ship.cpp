#include "ship.h"
#include "game.h"

Ship::Ship(Game* game, int id) : Object(game)
{
    object_type_ = ship;
    alive_ = true;
    can_stunned_ = true;
    attack_times_ = 1;
    stunned_ = 0;
    shield_health_ = 0;
    immune_ = 0;
    suck_ = 0;
    heal_ = 0;
    fury_ = 0;
    dodge_ = 0;
    burn_ = 0;
    id_ = id;
}

Ship::~Ship()
{
    int size = cannons_.size();
    for (int i = 0; i < size; i++)
        delete cannons_[i];
}

double Ship::GetHealth() const
{
    return health_;
}

void Ship::IncreaseHealth(double n)
{
    health_ = min(health_ + n, max_health_);
}

void Ship::DecreaseHealth(double n, Ship* source)
{
    if (source && source->IsSuck())
        source->IncreaseHealth(n);
    if (shield_health_)
        shield_health_ -= n;
    else
        health_ -= n;
    if (shield_health_ <= 0)
        shield_health_ = 0;
    if (health_ <= 0)
    {
        health_ = 0;
        alive_ = false;
    }
    Ban();
}

double Ship::GetMaxHealth() const
{
    return max_health_;
}

int Ship::GetId() const
{
    return id_;
}

bool Ship::GetCanStunned() const
{
    return can_stunned_;
}

int Ship::GetAttackTimes() const
{
    return attack_times_;
}

vector<Cannon*> Ship::GetCannons() const
{
    return cannons_;
}

vector<Skill*> Ship::GetSkills() const
{
    return skills_;
}

int Ship::GetNumCannons() const
{
    return cannons_.size();
}

int Ship::GetNumSkills() const
{
    return skills_.size();
}

ShipType Ship::GetShipType() const
{
    return ship_type_;
}

bool Ship::IsAlive() const
{
    return alive_;
}

void Ship::SetDead()
{
    alive_ = false;
}

int Ship::GetStunned() const
{
    return stunned_;
}

bool Ship::IsStunned() const
{
    return stunned_;
}

void Ship::IncreaseStun(int n)
{
    stunned_ += n;
}

int Ship::GetShieldHealth() const
{
    return shield_health_;
}

void Ship::IncreaseShieldHealth(int n)
{
    shield_health_ += n;
}

bool Ship::HasShield() const
{
    return shield_health_ != 0;
}

int Ship::GetImmune() const
{
    return immune_;
}

bool Ship::IsImmune() const
{
    return immune_;
}

void Ship::IncreaseImmune(int n)
{
    immune_ += n;
    stunned_ = 0;
    burn_ = 0;
}

int Ship::GetSuck() const
{
    return suck_;
}

bool Ship::IsSuck() const
{
    return suck_;
}

void Ship::IncreaseSuck(int n)
{
    suck_ += n;
}

int Ship::GetHeal() const
{
    return heal_;
}

bool Ship::IsHeal() const
{
    return heal_;
}

void Ship::IncreaseHeal(int n)
{
    heal_ += n;
}

int Ship::GetFury() const
{
    return fury_;
}

bool Ship::IsFury() const
{
    return fury_;
}

void Ship::IncreaseFury(int n)
{
    fury_ += n;
}

int Ship::GetDodge() const
{
    return dodge_;
}

bool Ship::IsDodge() const
{
    return dodge_;
}

void Ship::IncreaseDodge(int n)
{
    dodge_ += n;
}

int Ship::GetBurn() const
{
    return burn_;
}

bool Ship::IsBurn() const
{
    return burn_;
}

void Ship::IncreaseBurn(int n)
{
    burn_ += n;
}