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

        cout << "\033[0;36m" << player->GetName() << "\033[0m" << "'s status: " << endl;
        for (int i = 0; i < num; i++)
        {
            Ship* ship = ships[i];
            cout << "  " << i + 1 << "  ";
            cout << "\033[1;36m" << ship->GetName() << "\033[0m";
            if (ship->IsAlive())
            {
                if (ship->HasShield())
                    cout << "\033[0;32m" << "(shield: " << ship->GetShieldHealth() << ")" << "\033[0m";
                if (ship->IsImmune())
                    cout << "\033[1;35m" << "(immune: " << ship->GetImmune() << ")" << "\033[0m";
                if (ship->IsSuck())
                    cout << "\033[0;35m" << "(suck: " << ship->GetSuck() << ")" << "\033[0m";
                if (ship->IsHeal())
                    cout << "\033[1;32m" << "(heal: " << ship->GetHeal() << ")" << "\033[0m";
                if (ship->IsFury())
                    cout << "\033[0;33m" << "(fury: " << ship->GetFury() << ")" << "\033[0m";
                if (ship->IsDodge())
                    cout << "\033[1;34m" << "(dodge: " << ship->GetDodge() << ")" << "\033[0m";
                if (ship->IsStunned())
                    cout << "\033[1;33m" << "(stunned: " << ship->GetStunned() << ")" << "\033[0m";
                cout << "  Health: " << ship->GetHealth() << "  ";
                ShowCannonStatus(ship, false);
                ShowSkillStatus(ship, false);
                cout << endl;
            }
            else
                cout << "\033[1;31m" << "  Dead" << "\033[0m" << endl;
        }
    }
    cout << endl;
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
            cout << "\033[1;31m" << "(banned)" << "\033[0m";
        else if (cur->IsReady())
            cout << "\033[0;32m" << "(ready)" << "\033[0m";
        else
            cout << "(cd: " << cur->GetCd() << ")";
        cout << "  ";
    }
}

void Game::ShowSkillStatus(Ship* ship, bool showindex) const
{
    vector<Skill*> skills = ship->GetSkills();
    int num_cannons = ship->GetNumCannons();
    int num_skills = skills.size();
    for (int i = 0; i < num_skills; i++)
    {
        if (showindex)
            cout << i + 1 + num_cannons << ": ";
        Skill* cur = skills[i];
        cout << cur->GetName();
        if (cur->IsReady())
            cout << "\033[0;32m" << "(ready)" << "\033[0m";
        else
            cout << "(cd: " << cur->GetCd() << ")";
        cout << "  ";
    }
}

void Game::Input()
{
    cout << "It's " << "\033[0;36m" << cur_player_->GetName() << "\033[0m" << "'s turn." << endl;
    int num_ship = cur_player_->GetNum();
    vector<Ship*> ships = cur_player_->GetShips();

    for (int i = 0; i < num_ship; i++)
    {
        Ship* ship = ships[i];
        if (ship->IsAlive() && !ship->IsStunned())
        {
            cout << "  " << i + 1 << "  " << "\033[1;36m" << ship->GetName() << "\033[0m" << endl;
            cout << "\033[1;33m" << "  Cannons: " << "\033[0m";
            ShowCannonStatus(ship, true);
            cout << endl;
            if (ship->GetNumSkills())
            {
                cout << "\033[1;33m" << "  Skills: " << "\033[0m";
                ShowSkillStatus(ship, true);
                cout << endl;
            }
            cout << "Please input your choice. Enter 0 to rest."<< endl;

            vector<Cannon*> cannons = ship->GetCannons();
            vector<Skill*> skills = ship->GetSkills();
            int num_cannon = cannons.size();
            int num_skill = skills.size();

            int option;
            while (true)
            {
                InputNumber<int>(option, 0, num_cannon + num_skill);
                if (option != 0)
                {
                    if (option <= num_cannon)
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
                    else
                    {
                        if (!skills[option - num_cannon - 1]->IsReady())
                        {
                            cout << "This skill is in cooldown. Please input again." << endl;
                            continue;
                        }
                    }
                }
                break;
            }

            if (option != 0)
            {
                cout << "Please input target id: " << endl;
                int target;
                if (option <= num_cannon)
                {
                    Cannon* cur_cannon = cannons[option - 1];
                    CannonType type = cur_cannon->GetCannonType();
                    if (type == heal_cannon)
                    {
                        InputNumber<int>(target, 1, cur_player_->GetNum());
                        cannon_event_.push(new CannonEvent(cur_cannon, ship, cur_player_->GetShips()[target - 1]));
                    }
                    else if (type == split_cannon)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            InputNumber<int>(target, 1, other_player_->GetNum());
                            cannon_event_.push(new CannonEvent(cur_cannon, ship, other_player_->GetShips()[target - 1]));
                        }
                    }
                    else if (type == explosive_cannon)
                    {
                        InputNumber<int>(target, 1, other_player_->GetNum());
                        Ship* main_ship = other_player_->GetShips()[target - 1];
                        Ship* ship_1 = target == 1 ? nullptr : other_player_->GetShips()[target - 2];
                        Ship* ship_2 = target == other_player_->GetNum() ? nullptr : other_player_->GetShips()[target];
                        cannon_event_.push(new ExplosiveEvent(cur_cannon, ship, main_ship, ship_1, ship_2));
                    }
                    else
                    {
                        InputNumber<int>(target, 1, other_player_->GetNum());
                        cannon_event_.push(new CannonEvent(cur_cannon, ship, other_player_->GetShips()[target - 1]));
                    }
                }
                else
                {
                    Skill* cur_skill = skills[option - num_cannon - 1];
                    SkillType type = cur_skill->GetSkillType();
                    if (type == super_heal)
                    {
                        for (Ship* tar_ship : ships)
                            if (tar_ship->IsAlive())
                                skill_event_.push(new SkillEvent(cur_skill, ship, tar_ship));
                    }
                    else if (type == super_shield)
                    {
                        for (Ship* tar_ship : ships)
                            if (tar_ship->IsAlive())
                                skill_event_.push(new SkillEvent(cur_skill, ship, tar_ship));
                    }
                    else
                    {
                        InputNumber<int>(target, 1, cur_player_->GetNum());
                        skill_event_.push(new SkillEvent(cur_skill, ship,
                            cur_player_->GetShips()[target - 1]));
                    }
                }
            }
        }
    }
    cout << endl;
}

void Game::Update() 
{
    ProcessCannon();

    // update cd, stun, immune, suck, heal
    for (Ship* ship : cur_player_->GetShips())
        if (ship->IsAlive())
        {
            if (ship->IsImmune())
                ship->IncreaseImmune(-1);
            if (ship->IsSuck())
                ship->IncreaseSuck(-1);
            if (ship->IsHeal())
            {
                ship->IncreaseHealth(2);
                ship->IncreaseHeal(-1);
            }
            if (ship->IsDodge())
                ship->IncreaseDodge(-1);
            if (ship->IsStunned())
                ship->IncreaseStun(-1);
            else
            {
                if (ship->GetShipType() == heal_ship)
                    ship->IncreaseHealth(2);
                vector<Cannon*> cannons = ship->GetCannons();
                for (Cannon* cannon : cannons)
                    if (!cannon->IsReady())
                        cannon->SetCd(cannon->GetCd() - 1);
                vector<Skill*> skills = ship->GetSkills();
                for (Skill* skill : skills)
                    if (!skill->IsReady())
                        skill->SetCd(skill->GetCd() - 1);
            }
        }
    
    ProcessSkill();

    // update ingame info
    cur_player_->SetState(out);
    for (Ship* ship : cur_player_->GetShips())
        if (ship->IsAlive())
        {
            cur_player_->SetState(ingame);
            break;
        }
    other_player_->SetState(out);
    for (Ship* ship : other_player_->GetShips())
        if (ship->IsAlive())
        {
            other_player_->SetState(ingame);
            break;
        }
    
    // change turn
    swap(cur_player_, other_player_);
}

void Game::ProcessCannon()
{
    while (!cannon_event_.empty())
    {
        Event* event = cannon_event_.front();
        event->Process();
        delete event;
        cannon_event_.pop();
    }
}

void Game::ProcessSkill()
{
    while (!skill_event_.empty())
    {
        Event* event = skill_event_.front();
        event->Process();
        delete event;
        skill_event_.pop();
    }
}

void Game::Start()
{
    srand(time(nullptr));
    int round = 1;
    while (CheckInGame())
    {
        cout << "\033[0;35m";
        cout << endl << "Round " << round << ": " << endl << endl;
        cout << "\033[0m";
        ShowStatus();
        Input();
        Update();
        round++;
    }
    cout << "\033[1;35m";
    cout << other_player_->GetName() << " wins!" << endl;
    cout << "\033[0m";
}

bool Game::CheckInGame() const
{
    return player_1_->GetState() == ingame && player_2_->GetState() == ingame;
}