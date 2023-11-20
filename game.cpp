#include "game.h"

Game::Game(Player* player_1, Player* player_2)
{
    player_1_ = player_1;
    player_2_ = player_2;

    cur_player_ = player_1;
    other_player_ = player_2;

    skip_ = false;
}

Player* Game::GetCurPlayer() const
{
    return cur_player_;
}

Player* Game::GetOtherPlayer() const
{
    return other_player_;
}

GameResult Game::GetResult() const
{
    return result_;
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
                if (ship->IsBurn())
                    cout << "\033[0;31m" << "(burn: " << ship->GetBurn() << ")" << "\033[0m";
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
    if (cur_player_->GetType() == human)
    {
        cout << "It's " << "\033[0;36m" << cur_player_->GetName() << "\033[0m" << "'s turn." << endl;
        int num_ship = cur_player_->GetNum();
        vector<Ship*> ships = cur_player_->GetShips();

        bool all_stunned = true;
        for (int i = 0; i < num_ship; i++)
        {
            Ship* ship = ships[i];
            if (ship->IsAlive() && !ship->IsStunned())
            {
                all_stunned = false;
                break;
            }
        }
        if (all_stunned)
        {
            cout << "\033[0;32m" << "(press enter to continue)" << "\033[0m" << endl;
            fflush(stdin);
            getchar();
        }
        else
        {
            for (int i = 0; i < num_ship; i++)
            {
                Ship* ship = ships[i];
                if (ship->IsAlive() && !ship->IsStunned())
                {
                    cout << "  " << i + 1 << "  " << "\033[1;36m" << ship->GetName() << "\033[0m" << endl;
                    if (ship->GetNumCannons())
                    {
                        cout << "\033[1;33m" << "  Cannons: " << "\033[0m";
                        ShowCannonStatus(ship, true);
                        cout << endl;
                    }
                    if (ship->GetNumSkills())
                    {
                        cout << "\033[1;33m" << "  Skills: " << "\033[0m";
                        ShowSkillStatus(ship, true);
                        cout << endl;
                    }

                    vector<Cannon*> cannons = ship->GetCannons();
                    vector<Skill*> skills = ship->GetSkills();
                    int num_cannon = cannons.size();
                    int num_skill = skills.size();

                    for (int k = 0; k < ship->GetAttackTimes(); k++)
                    {
                        cout << "\033[0;32m" << "Attack " << k + 1 << ":" << "\033[0m" << endl;
                        cout << "Please input your choice. Enter 0 to rest."<< endl;
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
                            int target;
                            if (option <= num_cannon)
                            {
                                cout << "Please input target id: " << endl;
                                Cannon* cur_cannon = cannons[option - 1];
                                Player* target_player = cur_cannon->GetTargetType() == ally ? cur_player_ : other_player_;
                                for (int j = 0; j < cur_cannon->GetAttackTimes(); j++)
                                {
                                    InputNumber<int>(target, 1, target_player->GetNum());
                                    cannon_event_.push(new CannonEvent(cur_cannon, ship, target_player->GetShips()[target - 1]));
                                }
                                cur_cannon->SetCd(cur_cannon->GetMaxCd() + 1);
                            }
                            else
                            {
                                Skill* cur_skill = skills[option - num_cannon - 1];
                                Player* target_player = cur_skill->GetTargetType() == ally ? cur_player_ : other_player_;
                                queue<Event*>* target_queue = cur_skill->GetSkillProperty() == assist_skill ? &skill_event_ : &attack_skill_event_;
                                if (cur_skill->GetAttackTimes() == 0)
                                    target_queue->push(new SkillEvent(cur_skill, ship, nullptr));
                                else 
                                {
                                    cout << "Please input target id: " << endl;
                                    for (int j = 0; j < cur_skill->GetAttackTimes(); j++)
                                    {
                                        InputNumber<int>(target, 1, target_player->GetNum());
                                        target_queue->push(new SkillEvent(cur_skill, ship, target_player->GetShips()[target - 1]));
                                    }
                                }
                                cur_skill->SetCd(cur_skill->GetMaxCd() + 1);
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        cout << "It's " << "\033[0;36m" << cur_player_->GetName() << "\033[0m" << "'s turn." << endl;
        if (other_player_->GetType() == human)
        {
            cout << "\033[0;32m" << "(press enter to continue)" << "\033[0m" << endl;
            fflush(stdin);
            getchar();
        }
        else if (!skip_)
        {
            cout << "\033[0;32m" << "(press enter to continue, press 's' to skip)" << "\033[0m" << endl;
            fflush(stdin);
            if (getchar() == 's')
                skip_ = true;
        }

        int num_ship = cur_player_->GetNum();
        vector<Ship*> ships = cur_player_->GetShips();

        for (int i = 0; i < num_ship; i++)
        {
            Ship* ship = ships[i];
            if (ship->IsAlive() && !ship->IsStunned())
            {
                vector<Cannon*> cannons = ship->GetCannons();
                vector<Skill*> skills = ship->GetSkills();
                int num_cannon = cannons.size();
                int num_skill = skills.size();

                for (int k = 0; k < ship->GetAttackTimes(); k++)
                {
                    int option;
                    while (true)
                    {
                        option = rand() % (num_cannon + num_skill + 1);
                        if (option != 0)
                        {
                            if (option <= num_cannon)
                            {
                                if (!cannons[option - 1]->IsAvailable() || !cannons[option - 1]->IsReady())
                                    continue;
                            }
                            else
                            {
                                if (!skills[option - num_cannon - 1]->IsReady())
                                    continue;
                            }
                        }
                        break;
                    }

                    if (option == 0)
                        cout << i + 1 << " " << "\033[1;36m" << ship->GetName() << "\033[0m" << " rests" << endl;
                    else
                    {
                        string name = option <= num_cannon ? cannons[option - 1]->GetName() : 
                                      skills[option - num_cannon - 1]->GetName();
                        cout << i + 1 << " " << "\033[1;36m" << ship->GetName() << "\033[0m" << " uses ";
                        cout << "\033[0;33m" << name << "\033[0m" << ". ";

                        int target;
                        if (option <= num_cannon)
                        {
                            cout << "Target: ";
                            Cannon* cur_cannon = cannons[option - 1];
                            Player* target_player = cur_cannon->GetTargetType() == ally ? cur_player_ : other_player_;
                            for (int j = 0; j < cur_cannon->GetAttackTimes(); j++)
                            {
                                while (true)
                                {
                                    target = rand() % target_player->GetNum() + 1;
                                    if (target_player->GetShips()[target - 1]->IsAlive())
                                        break;
                                }
                                cannon_event_.push(new CannonEvent(cur_cannon, ship, target_player->GetShips()[target - 1]));
                                if (j)
                                    cout << ", ";
                                cout << target << " \033[1;36m" << target_player->GetShips()[target - 1]->GetName() << "\033[0m";
                            }
                            cur_cannon->SetCd(cur_cannon->GetMaxCd() + 1);
                            cout << "." << endl;
                        }
                        else
                        {
                            Skill* cur_skill = skills[option - num_cannon - 1];
                            Player* target_player = cur_skill->GetTargetType() == ally ? cur_player_ : other_player_;
                            queue<Event*>* target_queue = cur_skill->GetSkillProperty() == assist_skill ? &skill_event_ : &attack_skill_event_;
                            if (cur_skill->GetAttackTimes() == 0)
                            {
                                target_queue->push(new SkillEvent(cur_skill, ship, nullptr));
                                cout << endl;
                            }
                            else 
                            {
                                cout << "Target: ";
                                for (int j = 0; j < cur_skill->GetAttackTimes(); j++)
                                {
                                    while (true)
                                    {
                                        target = rand() % target_player->GetNum() + 1;
                                        if (target_player->GetShips()[target - 1]->IsAlive())
                                            break;
                                    }
                                    target_queue->push(new SkillEvent(cur_skill, ship, target_player->GetShips()[target - 1]));
                                    if (j)
                                        cout << ", ";
                                    cout << target << " \033[1;36m" << target_player->GetShips()[target - 1]->GetName() << "\033[0m";
                                }
                                cout << "." << endl;
                            }
                            cur_skill->SetCd(cur_skill->GetMaxCd() + 1);
                        }
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
    ProcessAttackSkill();
    ProcessSkill();

    // update cd, stun, immune, suck, heal, burn
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
            if (ship->IsBurn())
            {
                ship->DecreaseHealth(ship->GetBurn(), nullptr);
                ship->IncreaseBurn(-1);
            }
            if (ship->IsStunned())
                ship->IncreaseStun(-1);
            else
            {
                if (ship->GetShipType() == heal_ship || ship->GetShipType() == concatenation_boss)
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

void Game::ProcessAttackSkill()
{
    while (!attack_skill_event_.empty())
    {
        Event* event = attack_skill_event_.front();
        event->Process();
        delete event;
        attack_skill_event_.pop();
    }
}

void Game::Start()
{
    int round = 1;
    while (CheckInGame() && round <= 200)
    {
        cout << "\033[0;35m";
        cout << endl << "Round " << round << ": " << endl << endl;
        cout << "\033[0m";
        ShowStatus();
        Input();
        Update();
        round++;
    }
    cout << endl;
    ShowStatus();
    cout << "\033[1;35m";
    PlayerState state_1 = player_1_->GetState();
    PlayerState state_2 = player_2_->GetState();
    if ((state_1 == ingame && state_2 == ingame) || (state_1 == out && state_2 == out))
    {
        cout << "It's a tie." << endl;
        result_ = tie;
    }
    else if (state_1 == ingame)
    {
        cout << player_1_->GetName() << " wins!" << endl;
        result_ = side_1_win;
    }
    else
    {
        cout << player_2_->GetName() << " wins!" << endl;
        result_ = side_2_win;
    }
    cout << "\033[0m";
}

bool Game::CheckInGame() const
{
    return player_1_->GetState() == ingame && player_2_->GetState() == ingame;
}