#pragma once

#include <string>

using namespace std;

enum PlayerSide
{
    side_1,
    side_2
};

class Player
{
    public:
        Player(string name, PlayerSide side);
        ~Player() {}

        string GetName() const;
    
    private:
        string name_;
        PlayerSide side_;
};