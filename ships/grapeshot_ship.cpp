#include "grapeshot_ship.h"
#include "game.h"

GrapeshotShip::GrapeshotShip(Game* game, int id) : Ship(game, id)
{
    health_ = 18;
    max_health_ = 18;
    ship_type_ = grapeshot_ship;
    name_ = "Grapeshot Ship";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new Cannon2(game));
    cannons_.push_back(new Cannon3(game));
    skills_.push_back(new Grapeshot(game));
    skills_.push_back(new SuperGrapeshot(game));
}

void GrapeshotShip::Ban()
{
    if (health_ < 5)
        cannons_[2]->Ban();
    if (health_ < 3)
        cannons_[1]->Ban();
}