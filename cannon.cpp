#include "cannon.h"
#include "game.h"

Cannon::Cannon(Game* game) : Object(game)
{
    object_type_ = cannon;
}