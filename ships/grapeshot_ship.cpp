#include "grapeshot_ship.h"
#include "game.h"

GrapeshotShip::GrapeshotShip(Game* game, int id, Player* player) : Ship(game, id, player)
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