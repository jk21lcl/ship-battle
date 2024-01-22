#include "game.h"

using namespace std;

vector<int> cost_ship = {4,2,1,5,5,5,3,3,4,1,2,3,3,4,3,4,3,3};
vector<string> name_ship = {"Big Ship","Middle Ship","Small Ship","Defense Ship",
                       "Wizard Ship","Heal Ship","Crit Ship","Swift Ship",
                       "Grapeshot Ship","Small Explosive Ship",
                       "Medium Explosive Ship","Big Explosive Ship",
                       "Torpedo Ship","Igniting Ship","Random Ship",
                       "Specter Ship","Assassin Ship","Development Ship"};
int num_ship = 18;

vector<int> cost_boss = {40};
vector<string> name_boss = {"Concatenation Boss"};
int num_boss = 1;

vector<bool> available_ship[2] = {vector<bool>(num_ship, true), vector<bool>(num_ship, true)};
vector<bool> available_boss[2] = {vector<bool>(num_boss, true), vector<bool>(num_boss, true)};
int num_ship_ban[2] = {0,0};
int num_boss_ban[2] = {0,0};

enum GameMode
{
    battle,
    advanced,
    sandbox,
    random,
    boss,
    test
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
        case 14:
            game->AddShip<IgnitingShip>(side);
            break;
        case 15:
            game->AddShip<RandomShip>(side);
            break;
        case 16:
            game->AddShip<SpecterShip>(side);
            break;
        case 17:
            game->AddShip<AssassinShip>(side);
            break;
        case 18:
            game->AddShip<DevelopmentShip>(side);
            break;
        case 19:
            game->AddShip<ConcatenationBoss>(side);
            break;
        default:
            cout << "Input out of range." << endl;
            break;
    }
}

void ProcessBan(Player* player, int i) // i=0 means player 1, i=1 means player 2
{
    int choice;
    cout << "Enter the ships of " << "\033[0;36m" << player->GetName() << "\033[0m";
    cout << " that will be banned. Enter 0 to end." << endl;
    cout << "  ";
    for (int j = 1; j <= num_ship; j++)
    {
        cout << j << ": ";
        cout << "\033[1;36m" << name_ship[j - 1] << "\033[0m" << "(";
        cout << "\033[1;33m" << cost_ship[j - 1] << "\033[0m" << ")  ";
    }
    cout << endl;
    while (true)
    {
        InputNumber<int>(choice, 0, num_ship);
        if (choice == 0)
            break;
        if (available_ship[i][choice - 1])
        {
            if (num_ship_ban[i] == num_ship - 1)
            {
                cout << "You cannot ban all the ships." << endl;
                continue;
            }
            available_ship[i][choice - 1] = false;
            num_ship_ban[i]++;
        }
    }
}

// i=0 means player 1, i=1 means player 2
// show_boss=false only shows ships, show_boss=true shows both ships and bosses
void ShowOption(Player* player, int i, bool show_boss) 
{
    cout << "Enter the ships for " << "\033[0;36m" << player->GetName() << "\033[0m" << ". ";
    cout << "Enter 0 to end. " << endl;
    cout << "\033[1;33m" << "  Option: " << "\033[0m" << endl;
    cout << "    ";
    for (int j = 1; j <= num_ship; j++)
    {
        if (available_ship[i][j - 1])
        {
            cout << j << ": ";
            cout << "\033[1;36m" << name_ship[j - 1] << "\033[0m" << "(";
            cout << "\033[1;33m" << cost_ship[j - 1] << "\033[0m" << ")  ";
        }
    }
    if (show_boss)
        for (int j = 1; j <= num_boss; j++)
        {
            cout << j + num_ship << ": ";
            cout << "\033[1;36m" << name_boss[j - 1] << "\033[0m" << "(";
            cout << "\033[1;33m" << cost_boss[j - 1] << "\033[0m" << ")  ";
        }
    cout << endl;
}

int SelectBoss()
{
    cout << "Enter the boss you want to conquer." << endl;
    cout << "\033[1;33m" << "  Option: " << "\033[0m" << endl;
    cout << "    ";
    for (int j = 1; j <= num_boss; j++)
    {
        cout << j << ": ";
        cout << "\033[1;36m" << name_boss[j - 1] << "\033[0m" << "(";
        cout << "\033[1;33m" << cost_boss[j - 1] << "\033[0m" << ")  ";
    }
    cout << endl;
    int option;
    InputNumber(option, 1, num_boss);
    return option;
}

PlayerType InputPlayerType(Player* player)
{
    cout << "Please input the type of " << "\033[0;36m" << player->GetName() << "\033[0m" << ". ";
    cout << "0 for human, 1 for computer." << endl;
    int type;
    InputNumber(type, 0, 1);
    return (PlayerType)type;
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
    cout << "  5: boss" << endl;
    cout << "  6: test" << endl;
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
            ProcessBan(&player_1, 0);
            ProcessBan(&player_2, 1);
            cout << "Enter the money of " << "\033[0;36m" << player_2.GetName() << "\033[0m" << ". " << endl;
            cout << "\033[0;36m" << player_1.GetName() << "\033[0m" << " will get 85% of that." << endl;
            double money_1;
            double money_2;
            InputNumber<double>(money_2, 2, 1000);
            money_1 = money_2 * 0.85;

            for (int i = 0; i < 2; i++)
            {
                Player* player = i == 0 ? &player_1 : &player_2;
                PlayerSide side = i == 0 ? side_1 : side_2;
                double* money = i == 0 ? &money_1 : &money_2;
                cout << "\033[0;36m" << player->GetName() << "\033[0m" << " has money " << *money << endl;

                ShowOption(player, i, false);
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
                    if (!available_ship[i][choice - 1])
                    {
                        cout << "This ship has been banned. Please input again." << endl;
                        continue;
                    }
                    if (*money < cost_ship[choice - 1])
                    {
                        cout << "Your money is not enough." << endl;
                        continue;
                    }
                    AddShip(&game, side, choice);
                    *money -= cost_ship[choice - 1];
                    num++;
                }
            }
            break;
        }

        case sandbox:
        {
            player_1.SetType(InputPlayerType(&player_1));
            player_2.SetType(InputPlayerType(&player_2));
            for (int i = 0; i < 2; i++)
            {
                Player* player = i == 0 ? &player_1 : &player_2;
                PlayerSide side = i == 0 ? side_1 : side_2;

                ShowOption(player, i, true);
                int choice;
                int num = 0;
                while (true)
                {
                    InputNumber<int>(choice, 0, num_ship + num_boss);
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

        case random:
        {
            PlayerType type_1 = InputPlayerType(&player_1);
            PlayerType type_2 = InputPlayerType(&player_2);
            player_1.SetType(type_1);
            player_2.SetType(type_2);

            double share_1 = 0.85;
            double share_2 = 1;
            if (type_1 == computer)
                share_1 *= 1.46;
            if (type_2 == computer)
                share_2 *= 1.31;
            double ratio = round(share_1 / share_2 * 100);

            ProcessBan(&player_1, 0);
            ProcessBan(&player_2, 1);
            cout << "Enter the money of " << "\033[0;36m" << player_2.GetName() << "\033[0m" << ". " << endl;
            cout << "\033[0;36m" << player_1.GetName() << "\033[0m" << " will get " << ratio << "% of that." << endl;
            double money_1;
            double money_2;
            InputNumber<double>(money_2, 2, 1000);
            money_1 = money_2 * ratio / 100;

            for (int i = 0; i < 2; i++)
            {
                PlayerSide side = i == 0 ? side_1 : side_2;
                double* money = i == 0 ? &money_1 : &money_2;

                int min_cost = INT32_MAX;
                for (int j = 0; j < num_ship; j++)
                    if (available_ship[i][j] && cost_ship[j] < min_cost)
                        min_cost = cost_ship[j];
                
                while (*money >= min_cost)
                {
                    int choice = rand() % num_ship;
                    if (!available_ship[i][choice] || *money < cost_ship[choice])
                        continue;
                    AddShip(&game, side, choice + 1);
                    *money -= cost_ship[choice];
                }
            }
            break;
        }

        case boss:
        {
            int boss_id = SelectBoss();
            ProcessBan(&player_1, 0);
            player_2.SetType(computer);
            AddShip(&game, side_2, num_ship + boss_id);
            double money = cost_boss[boss_id - 1] * 0.65;

            int min_cost = INT32_MAX;
            for (int i = 0; i < num_ship; i++)
                if (available_ship[0][i] && cost_ship[i] < min_cost)
                    min_cost = cost_ship[i];
            
            while (money >= min_cost)
            {
                int choice = rand() % num_ship;
                if (!available_ship[0][choice] || money < cost_ship[choice])
                    continue;
                AddShip(&game, side_1, choice + 1);
                money -= cost_ship[choice];
            }

            break;
        }

        case test:
        {
            int win_times_1 = 0;
            int win_times_2 = 0;
            
            for (int times = 0; times < 20; times++)
            {
                Player player_1("player_1", side_1);
                Player player_2("player_2", side_2);
                Game game(&player_1, &player_2);

                player_1.SetType(computer);
                player_2.SetType(computer);

                double money_2 = 30;
                double money_1 = money_2 * 0.95;
                
                for (int i = 0; i < 2; i++)
                {
                    PlayerSide side = i == 0 ? side_1 : side_2;
                    double* money = i == 0 ? &money_1 : &money_2;
                    
                    while (*money >= 1)
                    {
                        int choice = rand() % num_ship;
                        if (!available_ship[i][choice] || *money < cost_ship[choice])
                            continue;
                        AddShip(&game, side, choice + 1);
                        *money -= cost_ship[choice];
                    }
                }
                game.Start();
                if (game.GetResult() == side_1_win)
                    win_times_1++;
                if (game.GetResult() == side_2_win)
                    win_times_2++;
            }

            cout << "\033[0;36m" << player_1.GetName() << "\033[0m" << " wins " << win_times_1 << " times" << endl;
            cout << "\033[0;36m" << player_2.GetName() << "\033[0m" << " wins " << win_times_2 << " times" << endl;
            return 0;
        }
    }

    game.Start();
    return 0;
}