#include "object.h"
#include "game.h"

Object::Object(Game* game)
{
    game_ = game;
}

string Object::GetName() const
{
    return name_;
}