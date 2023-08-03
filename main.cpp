#include "game.h"

using namespace std;

int main()
{
    Player player_1("player_1", side_1);
    Player player_2("player_2", side_2);
    Game game(&player_1, &player_2);

    game.AddShip<MiddleShip>(side_1);
    game.AddShip<MiddleShip>(side_1);
    game.AddShip<MiddleShip>(side_1);
    game.AddShip<SmallShip>(side_1);
    game.AddShip<MiddleShip>(side_2);
    game.AddShip<MiddleShip>(side_2);
    game.AddShip<MiddleShip>(side_2);
    game.AddShip<MiddleShip>(side_2);

    game.Start();
    return 0;
}