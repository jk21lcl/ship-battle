#pragma once

#include <string>

using namespace std;

enum PlayerSide
{
    side_1,
    side_2
};

enum PlayerState
{
    ingame,
    out
};

class Player
{
    public:
        Player(string name, PlayerSide side);
        ~Player() {}

        string GetName() const;
        PlayerState GetState() const;
        void SetState(PlayerState state);
    
    private:
        string name_;
        PlayerSide side_;
        PlayerState state_;
};