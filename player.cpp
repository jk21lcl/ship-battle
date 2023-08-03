#include "player.h"

Player::Player(string name, PlayerSide side)
{
    name_ = name;
    side_ = side;
}

string Player::GetName() const
{
    return name_;
}