#include "player.h"

Player::Player(string name, PlayerSide side)
{
    name_ = name;
    side_ = side;
    state_ = ingame;
}

string Player::GetName() const
{
    return name_;
}

PlayerState Player::GetState() const
{
    return state_;
}

void Player::SetState(PlayerState state)
{
    state_ = state;
}