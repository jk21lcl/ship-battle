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

void Game::GetInfo()
{
    player_this = turn_ == turn_1 ? player_1_ : player_2_;
    player_other = turn_ == turn_1 ? player_2_ : player_1_;
    ships_this = turn_ == turn_1 ? ships_1_ : ships_2_;
    ships_other = turn_ == turn_1 ? ships_2_ : ships_1_;
    num_this = turn_ == turn_1 ? num_1_ : num_2_;
    num_other = turn_ == turn_1 ? num_2_ : num_1_;
}

void Game::ShowStatus() const
{
    for (int j = 0; j < 2; j++)
    {
        Player* player = j == 0 ? player_1_ : player_2_;
        vector<Ship*> ships = j == 0 ? ships_1_ : ships_2_;
        int num = j == 0 ? num_1_ : num_2_;

        cout << player->GetName() << "'s status: " << endl;
        for (int i = 0; i < num; i++)
        {
            Ship* ship = ships[i];
            cout << "  " << i + 1 << "  ";
            cout << ship->GetName() << "  ";
            if (ship->IsAlive())
            {
                cout << "Health: " << ship->GetHealth() << "  ";
                ShowCannonStatus(ship, false);
                cout << endl;
            }
            else
                cout << "Dead" << endl;
        }
    }
    cout << endl;
}

void Game::Input()
{
    cout << "It's " << player_this->GetName() << "'s turn." << endl;
    for (int i = 0; i < num_this; i++)
    {
        Ship* ship = ships_this[i];
        if (ship->IsAlive())
        {
            cout << "  " << i + 1 << "  " << ship->GetName() << endl;
            cout << "  Option: " << endl;
            cout << "    ";
            cout << "0: rest  ";
            ShowCannonStatus(ship, true);
            cout << endl;
            cout << "Please input your choice: "<< endl;

            vector<Cannon*> cannons = ship->GetCannons();
            int num = cannons.size();

            int option;
            while (true)
            {
                cin >> option;
                if (option < 0 || option > num)
                {
                    cout << "Input out of range. Please input again." << endl;
                    continue;
                }
                if (option != 0 && !cannons[option - 1]->IsReady())
                {
                    cout << "This cannon is in cooldown. Please input again." << endl;
                    continue;
                }
                break;
            }

            if (option != 0)
            {
                cout << "Please input target id: " << endl;
                int target;
                while (true)
                {
                    cin >> target;
                    if (target >= 1 && target <= num_other)
                        break;
                    else
                        cout << "Input out of range. Please input again." << endl;
                }
                cannons[option - 1]->Attack(ship, ships_other[target - 1]);
            }
        }
    }
}

void Game::Update() 
{
    // update ingame info
    player_other->SetState(out);
    for (int i = 0; i < num_other; i++)
        if (ships_other[i]->IsAlive())
        {
            player_other->SetState(ingame);
            break;
        }
    
    // update cd
    for (Ship* ship : ships_this)
        if (ship->IsAlive())
        {
            vector<Cannon*> cannons = ship->GetCannons();
            for (Cannon* cannon : cannons)
                if (!cannon->IsReady())
                    cannon->SetCd(cannon->GetCd() - 1);
        }
    
    ChangeTurn();
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
        if (cur->IsReady())
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
        GetInfo();
        ShowStatus();
        Input();
        Update();
        round++;
    }
    cout << player_this->GetName() << " wins!" << endl;
}

bool Game::CheckInGame() const
{
    return player_1_->GetState() == ingame && player_2_->GetState() == ingame;
}

void Game::ChangeTurn()
{
    turn_ = turn_ == turn_1 ? turn_2 : turn_1;
}