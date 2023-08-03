#pragma once

#include <vector>
#include <string>

using namespace std;

class Game;

enum ObjectType
{
    ship,
    cannon
};

class Object
{
    public:
        Object(Game* game);
        ~Object() {}

        string GetName() const;
    
    protected:
        Game* game_;
        ObjectType object_type_;
        string name_;
};