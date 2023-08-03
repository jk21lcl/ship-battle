#pragma once

#include "ships.h"
#include "cannons.h"
#include "player.h"
#include <vector>

using namespace std;

class Game
{
    public:
        Game(Player* player_1, Player* player_2);
        ~Game();

        void Start();

        template<typename ship_type>
        void AddShip(PlayerSide side);
    
    private:
        Player* player_1_;
        Player* player_2_;
        vector<Ship*> ships_1_;
        vector<Ship*> ships_2_;
        int num_1_;
        int num_2_;

        void Show() const;
        void Input();
        void Update();
};