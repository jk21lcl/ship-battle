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

ObjectType Object::GetObjectType() const
{
    return object_type_;
}