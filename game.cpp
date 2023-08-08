#include "game.h"

Game::Game(Player* player_1, Player* player_2)
{
    player_1_ = player_1;
    player_2_ = player_2;

    cur_player_ = player_1;
    other_player_ = player_2;
}

void Game::ShowStatus() const
{
    for (int j = 0; j < 2; j++)
    {
        Player* player = j == 0 ? player_1_ : player_2_;
        int num = player->GetNum();
        vector<Ship*> ships = player->GetShips();

        cout << player->GetName() << "'s status: " << endl;
        for (int i = 0; i < num; i++)
        {
            Ship* ship = ships[i];
            cout << "  " << i + 1 << "  ";
            cout << ship->GetName();
            if (ship->IsAlive())
            {
                if (ship->IsSkipped())
                    cout << "(skipped)";
                cout << "  Health: " << ship->GetHealth() << "  ";
                ShowCannonStatus(ship, false);
                cout << endl;
            }
            else
                cout << "  Dead" << endl;
        }
    }
    cout << endl;
}

void Game::Input()
{
    cout << "It's " << cur_player_->GetName() << "'s turn." << endl;
    int num_ship = cur_player_->GetNum();
    vector<Ship*> ships = cur_player_->GetShips();

    for (int i = 0; i < num_ship; i++)
    {
        Ship* ship = ships[i];
        if (ship->IsAlive() && !ship->IsSkipped())
        {
            cout << "  " << i + 1 << "  " << ship->GetName() << endl;
            cout << "  Option: " << endl;
            cout << "    ";
            cout << "0: rest  ";
            ShowCannonStatus(ship, true);
            cout << endl;
            cout << "Please input your choice: "<< endl;

            vector<Cannon*> cannons = ship->GetCannons();
            int num_cannon = cannons.size();

            int option;
            while (true)
            {
                InputNumber<int>(option, 0, num_cannon);
                if (option != 0)
                {
                    if (!cannons[option - 1]->IsAvailable())
                    {
                        cout << "This cannon is banned. Please input again." << endl;
                        continue;
                    }
                    if (!cannons[option - 1]->IsReady())
                    {
                        cout << "This cannon is in cooldown. Please input again." << endl;
                        continue;
                    }
                }
                break;
            }

            if (option != 0)
            {
                cout << "Please input target id: " << endl;
                int target;
                InputNumber<int>(target, 1, other_player_->GetNum());
                cannons[option - 1]->Attack(ship, other_player_->GetShips()[target - 1]);
            }
        }
    }
}

void Game::Update() 
{
    // update ingame info
    other_player_->SetState(out);
    for (Ship* ship : other_player_->GetShips())
        if (ship->IsAlive())
        {
            other_player_->SetState(ingame);
            break;
        }
    
    // update cd and skip
    for (Ship* ship : cur_player_->GetShips())
        if (ship->IsAlive())
        {
            if (ship->IsSkipped())
                ship->SetSkip(false);
            else
            {
                vector<Cannon*> cannons = ship->GetCannons();
                for (Cannon* cannon : cannons)
                    if (!cannon->IsReady())
                        cannon->SetCd(cannon->GetCd() - 1);
            }
        }
    
    // change turn
    swap(cur_player_, other_player_);
}

void Game::ShowCannonStatus(Ship* ship, bool showindex) const
{
    vector<Cannon*> cannons = ship->GetCannons();
    int num = cannons.size();
    for (int i = 0; i < num; i++)
    {
        if (showindex)
            cout << i + 1 << ": ";
        Cannon* cur = cannons[i];
        cout << cur->GetName();
        if (!cur->IsAvailable())
            cout << "(banned)";
        else if (cur->IsReady())
            cout << "(ready)";
        else
            cout << "(cd: " << cur->GetCd() << ")";
        cout << "  ";
    }
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
    cout << other_player_->GetName() << " wins!" << endl;
}

bool Game::CheckInGame() const
{
    return player_1_->GetState() == ingame && player_2_->GetState() == ingame;
}