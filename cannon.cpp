#include "cannon.h"
#include "game.h"

Cannon::Cannon(Game* game) : Object(game)
{
    object_type_ = cannon;
    available_ = true;
}

void Cannon::SetCd(int cd)
{
    cd_ = cd;
}

int Cannon::GetCd() const
{
    return cd_;
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