#include "game.h"

using namespace std;

vector<int> cost = {4,2,1,5,5,5,3,3};
vector<string> name = {"Big Ship","Middle Ship","Small Ship","Defense Ship",
                       "Wizard Ship","Heal Ship","Crit Ship","Swift Ship"};
int num_ship = 8;

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
        case 4:
            game->AddShip<DefenseShip>(side);
            break;
        case 5:
            game->AddShip<WizardShip>(side);
            break;
        case 6:
            game->AddShip<HealShip>(side);
            break;
        case 7:
            game->AddShip<CritShip>(side);
            break;
        case 8:
            game->AddShip<SwiftShip>(side);
            break;
        default:
            cout << "Input out of range." << endl;
            break;
    }
}

void ShowOption(Player* player)
{
    cout << "Enter the ships for " << "\033[0;36m" << player->GetName() << "\033[0m" << ". ";
    cout << "Enter 0 to end. " << endl;
    cout << "\033[1;33m" << "  Option: " << "\033[0m" << endl;
    cout << "    ";
    for (int j = 1; j <= num_ship; j++)
    {
        cout << j << ": ";
        cout << "\033[1;36m" << name[j - 1] << "\033[0m" << "(";
        cout << "\033[1;33m" << cost[j - 1] << "\033[0m" << ")  ";
    }
    cout << endl;
}

int main()
{
    cout << "\033[0m";

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
            cout << "Enter the money of " << "\033[0;36m" << player_2.GetName() << "\033[0m" << ". " << endl;
            cout << "\033[0;36m" << player_1.GetName() << "\033[0m" << " will get 80% of that." << endl;
            double money_1;
            double money_2;
            InputNumber<double>(money_2, 2, 1000);
            money_1 = money_2 * 0.8;

            for (int i = 0; i < 2; i++)
            {
                Player* player = i == 0 ? &player_1 : &player_2;
                PlayerSide side = i == 0 ? side_1 : side_2;
                double* money = i == 0 ? &money_1 : &money_2;
                cout << "\033[0;36m" << player->GetName() << "\033[0m" << " has money " << *money << endl;

                ShowOption(player);
                int choice;
                int num = 0;
                while (true)
                {
                    InputNumber<int>(choice, 0, num_ship);
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

                ShowOption(player);
                int choice;
                int num = 0;
                while (true)
                {
                    InputNumber<int>(choice, 0, num_ship);
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