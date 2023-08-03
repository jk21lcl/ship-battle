#include "cannon_4.h"
#include "game.h"

Cannon4::Cannon4(Game* game) : Cannon(game)
{
    cannon_type_ = cannon_4;
    name_ = "Cannon4";
}

void Cannon4::Attack(Ship* source, Ship* target)
{
    target->SetHealth(target->GetHealth() - 4);
}