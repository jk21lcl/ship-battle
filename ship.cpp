#include "ship.h"
#include "game.h"

Ship::Ship(Game* game) : Object(game)
{
    object_type_ = ship;
    alive_ = true;
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
    health_ = health;
    Ban();
}

vector<Cannon*> Ship::GetCannons() const
{
    return cannons_;
}

bool Ship::IsAlive() const
{
    return alive_;
}