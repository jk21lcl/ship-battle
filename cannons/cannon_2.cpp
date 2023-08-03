#include "cannon_2.h"
#include "game.h"

Cannon2::Cannon2(Game* game) : Cannon(game)
{
    cannon_type_ = cannon_2;
    name_ = "Cannon2";
}

void Cannon2::Attack(Ship* source, Ship* target)
{
    target->SetHealth(target->GetHealth() - 2);
}