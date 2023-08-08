#pragma once

#include "player.h"
#include <vector>
#include <iostream>

using namespace std;

class Game
{
    public:
        Game(Player* player_1, Player* player_2);
        ~Game() {}

        void Start();

        template<typename ship_type>
        void AddShip(PlayerSide side)
        {
            switch (side)
            {
                case side_1:
                    player_1_->AddShip<ship_type>(this);
                    break;
                case side_2:
                    player_2_->AddShip<ship_type>(this);
                    break;
            }
        }
    
    private:
        Player* player_1_;
        Player* player_2_;

        Player* cur_player_;
        Player* other_player_;

        void ShowStatus() const;
        void Input();
        void Update();
        void ShowCannonStatus(Ship* ship, bool showindex) const;

        bool CheckInGame() const;
};

template<typename T>
void InputNumber(T& tar, T m, T n) // input a number in [m, n] to tar
{
    while (true)
    {
        cin >> tar;
        if (tar < m || tar > n)
        {
            cout << "Input out of range. Please input again." << endl;
            continue;
        }
        break;
    }
}