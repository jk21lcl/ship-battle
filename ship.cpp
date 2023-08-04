#include "ship.h"
#include "game.h"

Ship::Ship(Game* game) : Object(game)
{
    object_type_ = ship;
    alive_ = true;
    skipped_ = false;
}

Ship::~Ship()
{
    int size = cannons_.size();
    for (int i = 0; i < size; i++)
        delete cannons_[i];
}

int Ship::GetHealth() const
{
    return health_;
}

void Ship::SetHealth(int health)
{
    if (health <= 0)
    {
        health_ = 0;
        alive_ = false;
    }
    health_ = min(health, max_health_);
    Ban();
}

int Ship::GetMaxHealth() const
{
    return max_health_;
}

vector<Cannon*> Ship::GetCannons() const
{
    return cannons_;
}

bool Ship::IsAlive() const
{
    return alive_;
}

bool Ship::IsSkipped() const
{
    return skipped_;
}

void Ship::SetSkip(bool skipped)
{
    skipped_ = skipped;
}