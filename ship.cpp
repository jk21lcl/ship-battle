#include "ship.h"
#include "game.h"

Ship::Ship(Game* game) : Object(game)
{
    object_type_ = ship;
    alive_ = true;
    stunned_ = 0;
    shield_health_ = 0;
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

vector<Cannon*> Ship::GetCannons() const
{
    return cannons_;
}

ShipType Ship::GetShipType() const
{
    return ship_type_;
}

bool Ship::IsAlive() const
{
    return alive_;
}

int Ship::GetStunned() const
{
    return stunned_;
}

bool Ship::IsStunned() const
{
    return stunned_ ;
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