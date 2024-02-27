#pragma once

#include "player.h"
#include "events.h"
#include <vector>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <limits>
#include <cmath>

using namespace std;

enum GameResult
{
    side_1_win,
    side_2_win,
    tie
};

struct StabInfo
{
    Ship* source;
    Ship* target;
};

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

        Player* GetCurPlayer() const;
        Player* GetOtherPlayer() const;
        GameResult GetResult() const;
        void AddStabInfo(StabInfo stab_info);
    
    private:
        Player* player_1_;
        Player* player_2_;

        Player* cur_player_;
        Player* other_player_;

        queue<Event*> cannon_event_;
        queue<Event*> skill_event_;
        queue<Event*> attack_skill_event_;
        queue<Event*> dismantle_bomb_event_;

        vector<bool> alive_info_; // track the aliveness of each ship of other_player
        vector<StabInfo> stab_info_;

        GameResult result_;
        bool skip_; // whether skipping the details of computer-computer

        void ShowStatus() const;
        void ShowCannonStatus(Ship* ship, bool showindex) const;
        void ShowSkillStatus(Ship* ship, bool showindex) const;
        void Input();
        void Update();
        void ProcessCannon();
        void ProcessSkill();
        void ProcessAttackSkill();
        void ProcessDismantleBomb();

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