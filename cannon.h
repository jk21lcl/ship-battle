#pragma once

#include "object.h"

class Ship;

enum CannonType
{
    cannon_1,
    cannon_2,
    cannon_3,
    cannon_4,
    cannon_5
};

class Cannon : public Object
{
    public:
        Cannon(Game* game);
        virtual ~Cannon() {}

        virtual void Attack(Ship* source, Ship* target) = 0;
    
    protected:
        CannonType cannon_type_;
};