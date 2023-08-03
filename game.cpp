#include "game.h"

Game::Game(Player* player_1, Player* player_2)
{
    player_1_ = player_1;
    player_2_ = player_2;
    num_1_ = 0;
    num_2_ = 0;
    turn_ = turn_1;
}

Game::~Game()
{
    for (int i = 0; i < num_1_; i++)
        delete ships_1_[i];
    for (int i = 0; i < num_2_; i++)
        delete ships_2_[i];
}

void Game::ShowStatus() const
{
    cout << player_1_->GetName() << "'s status: " << endl;
    for (int i = 0; i < num_1_; i++)
    {
        Ship* ship = ships_1_[i];
        cout << "  " << i + 1 << "  ";
        cout << ship->GetName() << "  ";
        if (ship->IsAlive())
            cout << "Health: " << ship->GetHealth() << endl;
        else
            cout << "Dead" << endl;
    }
    cout << player_2_->GetName() << "'s status: " << endl;
    for (int i = 0; i < num_2_; i++)
    {
        Ship* ship = ships_2_[i];
        cout << "  " << i + 1 << "  ";
        cout << ship->GetName() << "  ";
        if (ship->IsAlive())
            cout << "Health: " << ship->GetHealth() << endl;
        else
            cout << "Dead" << endl;
    }
    cout << endl;
}

void Game::Input()
{
    if (turn_ == turn_1)
    {
        cout << "It's " << player_1_->GetName() << "'s turn." << endl;
        for (int i = 0; i < num_1_; i++)
        {
            Ship* ship = ships_1_[i];
            if (ship->IsAlive())
            {
                cout << "  " << i + 1 << "  " << ship->GetName() << endl;
                cout << "  Option: " << endl;
                cout << "    ";
                vector<Cannon*> cannons = ship->GetCannons();
                int num = cannons.size();
                cout << "0: rest  ";
                for (int j = 0; j < num; j++)
                    cout << j + 1 << ": " << cannons[j]->GetName() << "  ";
                cout << endl;
                cout << "Please input your choice: "<< endl;

                int option;
                while (true)
                {
                    cin >> option;
                    if (option >= 0 && option <= num)
                        break;
                    else
                        cout << "Input out of range. Please input again." << endl;
                }

                if (option != 0)
                {
                    cout << "Please input target id: " << endl;
                    int target;
                    while (true)
                    {
                        cin >> target;
                        if (target >= 1 && target <= num_2_)
                            break;
                        else
                            cout << "Input out of range. Please input again." << endl;
                    }
                    cannons[option - 1]->Attack(ship, ships_2_[target - 1]);
                }
            }
        }
    }
    else
    {
        cout << "It's " << player_2_->GetName() << "'s turn." << endl;
        for (int i = 0; i < num_2_; i++)
        {
            Ship* ship = ships_2_[i];
            if (ship->IsAlive())
            {
                cout << "  " << i + 1 << "  " << ship->GetName() << endl;
                cout << "  Option: " << endl;
                cout << "    ";
                vector<Cannon*> cannons = ship->GetCannons();
                int num = cannons.size();
                cout << "0: rest  ";
                for (int j = 0; j < num; j++)
                    cout << j + 1 << ": " << cannons[j]->GetName() << "  ";
                cout << endl;
                cout << "Please input your choice: "<< endl;

                int option;
                while (true)
                {
                    cin >> option;
                    if (option >= 0 && option <= num)
                        break;
                    else
                        cout << "Input out of range. Please input again." << endl;
                }

                if (option != 0)
                {
                    cout << "Please input target id: " << endl;
                    int target;
                    while (true)
                    {
                        cin >> target;
                        if (target >= 1 && target <= num_1_)
                            break;
                        else
                            cout << "Input out of range. Please input again." << endl;
                    }
                    cannons[option - 1]->Attack(ship, ships_1_[target - 1]);
                }
            }
        }
    }
}

void Game::Update() 
{
    player_1_->SetState(out);
    player_2_->SetState(out);
    for (int i = 0; i < num_1_; i++)
        if (ships_1_[i]->IsAlive())
        {
            player_1_->SetState(ingame);
            break;
        }
    for (int i = 0; i < num_2_; i++)
        if (ships_2_[i]->IsAlive())
        {
            player_2_->SetState(ingame);
            break;
        }
    ChangeTurn();
}

void Game::Start()
{
    int round = 1;
    while (CheckInGame())
    {
        cout << endl << "Round " << round << ": " << endl << endl;
        ShowStatus();
        Input();
        Update();
        round++;
    }
    if (player_1_->GetState() == ingame)
        cout << player_1_->GetName() << " wins!" << endl;
    else
        cout << player_2_->GetName() << " wins!" << endl;
}

bool Game::CheckInGame() const
{
    return player_1_->GetState() == ingame && player_2_->GetState() == ingame;
}

void Game::ChangeTurn()
{
    turn_ = turn_ == turn_1 ? turn_2 : turn_1;
}