#include "player.h"

Player::Player(string name, PlayerSide side)
{
    name_ = name;
    side_ = side;
    state_ = ingame;
    type_ = human;
    num_ = 0;
}

Player::~Player()
{
    for (int i = 0; i < num_; i++)
        delete ships_[i];
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

PlayerType Player::GetType() const
{
    return type_;
}

void Player::SetType(PlayerType type)
{
    type_ = type;
}

vector<Ship*> Player::GetShips() const
{
    return ships_;
}

int Player::GetNum() const
{
    return num_;
}