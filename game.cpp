#include "game.h"

Game::Game(Player* player_1, Player* player_2)
{
    player_1_ = player_1;
    player_2_ = player_2;
}

Game::~Game()
{
    for (int i = 0; i < num_1_; i++)
        delete ships_1_[i];
    for (int i = 0; i < num_2_; i++)
        delete ships_2_[i];
}

template<typename ship_type>
void Game::AddShip(PlayerSide side)
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