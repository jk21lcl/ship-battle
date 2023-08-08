#include "game.h"

using namespace std;

enum GameMode
{
    battle,
    advanced,
    sandbox
};

void AddShip(Game* game, PlayerSide side, int type)
{
    switch (type)
    {
        case 1:
            game->AddShip<BigShip>(side);
            break;
        case 2:
            game->AddShip<MiddleShip>(side);
            break;
        case 3:
            game->AddShip<SmallShip>(side);
            break;
        default:
            cout << "Input out of range." << endl;
            break;
    }
}

int main()
{
    Player player_1("player_1", side_1);
    Player player_2("player_2", side_2);
    Game game(&player_1, &player_2);

    int mode;
    cout << "Choose game mode: " << endl;
    cout << "  1: battle" << endl;
    cout << "  2: advanced" << endl;
    cout << "  3: sandbox" << endl;
    InputNumber<int>(mode, 1, 3);

    GameMode M = (GameMode)(mode - 1);
    switch (M)
    {
        case battle:
        {
            game.AddShip<MiddleShip>(side_1);
            game.AddShip<MiddleShip>(side_1);
            game.AddShip<MiddleShip>(side_1);
            game.AddShip<SmallShip>(side_1);
            game.AddShip<MiddleShip>(side_2);
            game.AddShip<MiddleShip>(side_2);
            game.AddShip<MiddleShip>(side_2);
            game.AddShip<MiddleShip>(side_2);
            break;
        }

        case advanced:
        {
            vector<int> cost = {4,2,1};
            cout << "Enter the money of " << player_2.GetName() << ". ";
            cout << player_1.GetName() << " will get 80% of that." << endl;
            double money_1;
            double money_2;
            InputNumber<double>(money_2, 2, 1000);
            money_1 = money_2 * 0.8;

            for (int i = 0; i < 2; i++)
            {
                Player* player = i == 0 ? &player_1 : &player_2;
                PlayerSide side = i == 0 ? side_1 : side_2;
                double* money = i == 0 ? &money_1 : &money_2;
                cout << player->GetName() << " has money " << *money << endl;

                cout << "Enter the ships for " << player->GetName() << ". ";
                cout << "Enter 0 to end. " << endl;
                cout << "  Option: " << endl;
                cout << "    1: BigShip(4)  2: MiddleShip(2)  3: SmallShip(1)" << endl;

                int choice;
                int num = 0;
                while (true)
                {
                    InputNumber<int>(choice, 0, 3);
                    if (choice == 0)
                    {
                        if (num == 0)
                        {
                            cout << "You haven't chosen a ship yet." << endl;
                            continue;
                        }
                        else
                            break;
                    }
                    if (*money < cost[choice - 1])
                    {
                        cout << "Your money is not enough." << endl;
                        continue;
                    }
                    AddShip(&game, side, choice);
                    *money -= cost[choice - 1];
                    num++;
                }
            }
            break;
        }

        case sandbox:
        {
            for (int i = 0; i < 2; i++)
            {
                Player* player = i == 0 ? &player_1 : &player_2;
                PlayerSide side = i == 0 ? side_1 : side_2;

                cout << "Enter the ships for " << player->GetName() << ". ";
                cout << "Enter 0 to end. " << endl;
                cout << "  Option: " << endl;
                cout << "    1: BigShip  2: MiddleShip  3: SmallShip" << endl;

                int choice;
                int num = 0;
                while (true)
                {
                    InputNumber<int>(choice, 0, 3);
                    if (choice == 0)
                    {
                        if (num == 0)
                        {
                            cout << "You haven't chosen a ship yet." << endl;
                            continue;
                        }
                        else
                            break;
                    }
                    AddShip(&game, side, choice);
                    num++;
                }
            }
            break;
        }
    }

    game.Start();
    return 0;
}