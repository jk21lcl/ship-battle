#pragma once

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
    
    protected:
        Game* game_;
        ObjectType object_type_;
};