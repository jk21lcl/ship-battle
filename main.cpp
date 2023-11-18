#include "game.h"

using namespace std;

vector<int> cost = {4,2,1,5,5,5,3,3,4,1,2,3,3};
vector<string> name = {"Big Ship","Middle Ship","Small Ship","Defense Ship",
                       "Wizard Ship","Heal Ship","Crit Ship","Swift Ship",
                       "Grapeshot Ship","Small Explosive Ship",
                       "Medium Explosive Ship","Big Explosive Ship",
                       "Torpedo Ship"};
int num_ship = 13;

vector<bool> available_1(num_ship, true);
vector<bool> available_2(num_ship, true);
int num_ban[2] = {0,0};

enum GameMode
{
    battle,
    advanced,
    sandbox,
    random,
    sandbox_computer,
    random_computer
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
        case 9:
            game->AddShip<GrapeshotShip>(side);
            break;
        case 10:
            game->AddShip<SmallExplosiveShip>(side);
            break;
        case 11:
            game->AddShip<MediumExplosiveShip>(side);
            break;
        case 12:
            game->AddShip<BigExplosiveShip>(side);
            break;
        case 13:
            game->AddShip<TorpedoShip>(side);
            break;
        default:
            cout << "Input out of range." << endl;
            break;
    }
}

void ProcessBan(Player* player_1, Player* player_2)
{
    for (int i = 0; i < 2; i++)
    {
        string player_name = i == 0 ? player_1->GetName() : player_2->GetName();
        vector<bool>* available = i == 0 ? &available_1 : &available_2;

        int choice;
        cout << "Enter the ships of " << "\033[0;36m" << player_name << "\033[0m";
        cout << " that will be banned. Enter 0 to end." << endl;
        cout << "  ";
        for (int j = 1; j <= num_ship; j++)
        {
            cout << j << ": ";
            cout << "\033[1;36m" << name[j - 1] << "\033[0m" << "(";
            cout << "\033[1;33m" << cost[j - 1] << "\033[0m" << ")  ";
        }
        cout << endl;
        while (true)
        {
            InputNumber<int>(choice, 0, num_ship);
            if (choice == 0)
                break;
            if ((*available)[choice - 1])
            {
                if (num_ban[i] == num_ship - 1)
                {
                    cout << "You cannot ban all the ships." << endl;
                    continue;
                }
                (*available)[choice - 1] = false;
                num_ban[i]++;
            }
        }
    }
}

void ShowOption(Player* player, int i)
{
    vector<bool>* available = i == 0 ? &available_1 : &available_2;
    cout << "Enter the ships for " << "\033[0;36m" << player->GetName() << "\033[0m" << ". ";
    cout << "Enter 0 to end. " << endl;
    cout << "\033[1;33m" << "  Option: " << "\033[0m" << endl;
    cout << "    ";
    for (int j = 1; j <= num_ship; j++)
    {
        if ((*available)[j - 1])
        {
            cout << j << ": ";
            cout << "\033[1;36m" << name[j - 1] << "\033[0m" << "(";
            cout << "\033[1;33m" << cost[j - 1] << "\033[0m" << ")  ";
        }
    }
    cout << endl;
}

int main()
{
    srand(time(nullptr));
    cout << "\033[0m";

    Player player_1("player_1", side_1);
    Player player_2("player_2", side_2);
    Game game(&player_1, &player_2);

    int mode;
    cout << "Choose game mode: " << endl;
    cout << "  1: battle" << endl;
    cout << "  2: advanced" << endl;
    cout << "  3: sandbox" << endl;
    cout << "  4: random" << endl;
    cout << "  5: sandbox + computer" << endl;
    cout << "  6: random + computer" << endl;
    InputNumber<int>(mode, 1, 6);

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
            ProcessBan(&player_1, &player_2);
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
                vector<bool>* available = i == 0 ? &available_1 : &available_2;
                cout << "\033[0;36m" << player->GetName() << "\033[0m" << " has money " << *money << endl;

                ShowOption(player, i);
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
                    if (!(*available)[choice - 1])
                    {
                        cout << "This ship has been banned. Please input again." << endl;
                        continue;
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

        case sandbox: case sandbox_computer:
        {
            if (M == sandbox_computer)
                game.GetOtherPlayer()->SetType(computer);
            for (int i = 0; i < 2; i++)
            {
                Player* player = i == 0 ? &player_1 : &player_2;
                PlayerSide side = i == 0 ? side_1 : side_2;

                ShowOption(player, i);
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

        case random: case random_computer:
        {
            if (M == random_computer)
                game.GetOtherPlayer()->SetType(computer);
            double ratio = M == random_computer ? 0.65 : 0.8;
            ProcessBan(&player_1, &player_2);
            cout << "Enter the money of " << "\033[0;36m" << player_2.GetName() << "\033[0m" << ". " << endl;
            cout << "\033[0;36m" << player_1.GetName() << "\033[0m" << " will get " << ratio * 100 << "% of that." << endl;
            double money_1;
            double money_2;
            InputNumber<double>(money_2, 2, 1000);
            money_1 = money_2 * ratio;

            for (int i = 0; i < 2; i++)
            {
                PlayerSide side = i == 0 ? side_1 : side_2;
                double* money = i == 0 ? &money_1 : &money_2;
                vector<bool>* available = i == 0 ? &available_1 : &available_2;

                int min_cost = 100;
                for (int i = 0; i < num_ship; i++)
                    if ((*available)[i] && cost[i] < min_cost)
                        min_cost = cost[i];
                
                while (*money >= min_cost)
                {
                    int choice = rand() % num_ship;
                    if (!(*available)[choice] || *money < cost[choice])
                        continue;
                    AddShip(&game, side, choice + 1);
                    *money -= cost[choice];
                }
            }
            break;
        }
    }

    game.Start();
    return 0;
}