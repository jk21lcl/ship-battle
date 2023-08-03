#pragma once

#include "ships.h"
#include "cannons.h"
#include "player.h"
#include <vector>
#include <iostream>

using namespace std;

enum Turn
{
    turn_1,
    turn_2
};

class Game
{
    public:
        Game(Player* player_1, Player* player_2);
        ~Game();

        void Start();

        template<typename ship_type>
        void AddShip(PlayerSide side)
        {
            switch (side)
            {
                case side_1:
                    ships_1_.push_back(new ship_type(this));
                    num_1_++;
                    break;
                case side_2:
                    ships_2_.push_back(new ship_type(this));
                    num_2_++;
                    break;
            }
        }
    
    private:
        Player* player_1_;
        Player* player_2_;
        vector<Ship*> ships_1_;
        vector<Ship*> ships_2_;
        int num_1_;
        int num_2_;
        Turn turn_;

        void ShowStatus() const;
        void Input();
        void Update();

        bool CheckInGame() const;
        void ChangeTurn();
};