#pragma once

#include "ships.h"
#include "cannons.h"
#include "skills.h"
#include <string>
#include <vector>

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

enum PlayerType
{
    human,
    computer
};

class Player
{
    public:
        Player(string name, PlayerSide side);
        ~Player();

        string GetName() const;
        PlayerState GetState() const;
        void SetState(PlayerState state);
        PlayerType GetType() const;
        void SetType(PlayerType type);

        vector<Ship*> GetShips() const;
        int GetNum() const;

        template<typename ship_type>
        void AddShip(Game* game)
        {
            ships_.push_back(new ship_type(game, num_ + 1, this));
            num_++;
        }
    
    private:
        string name_;
        PlayerSide side_;
        PlayerState state_;
        PlayerType type_;

        vector<Ship*> ships_;
        int num_;
};