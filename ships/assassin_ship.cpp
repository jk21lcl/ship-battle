#include "assassin_ship.h"
#include "game.h"

AssassinShip::AssassinShip(Game* game, int id) : Ship(game, id)
{
    health_ = 12;
    max_health_ = 12;
    ship_type_ = assassin_ship;
    name_ = "Assassin Ship";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new Cannon2(game));
    skills_.push_back(new Sacrifice(game_));
    skills_.push_back(new Lock(game_));
    skills_.push_back(new Stab(game_));
    Update();
}

void AssassinShip::Update()
{
    if (health_ >= 9)
    {
        skills_[0]->SetActive(true);
        skills_[1]->SetActive(false);
        skills_[2]->SetActive(false);
    }
    else if (health_ >= 5)
    {
        skills_[0]->SetActive(false);
        skills_[1]->SetActive(true);
        skills_[2]->SetActive(false);
    }
    else
    {
        skills_[0]->SetActive(false);
        skills_[1]->SetActive(false);
        skills_[2]->SetActive(true);
    }
}