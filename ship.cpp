#include "ship.h"
#include "game.h"

Ship::Ship(Game* game) : Object(game)
{
    object_type_ = ship;
}

int Ship::GetHealth() const
{
    return health_;
}

void Ship::SetHealth(int health)
{
    health_ = health;
}