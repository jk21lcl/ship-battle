#pragma once

#include "object.h"

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
        ~Cannon() {}

        virtual void Attack(int id);
    
    protected:
        CannonType cannon_type_;
};