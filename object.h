#pragma once

#include <vector>
#include <string>

using namespace std;

class Game;

enum ObjectType
{
    ship,
    cannon,
    skill
};

enum TargetType
{
    ally,
    enemy
};

class Object
{
    public:
        Object(Game* game);
        ~Object() {}

        string GetName() const;
        ObjectType GetObjectType() const;
    
    protected:
        Game* game_;
        ObjectType object_type_;
        string name_;
};