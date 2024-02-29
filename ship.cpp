#include "ship.h"
#include "game.h"

Ship::Ship(Game* game, int id, Player* player) : Object(game)
{
    object_type_ = ship;
    alive_ = true;
    can_stunned_ = true;
    attack_times_ = 1;
    dodge_prob_ = 0;
    heal_health_ = 0;
    absolute_damage_reduce_ = 0;
    ratio_damage_reduce_ = 0;
    shield_rebound_ = 0;

    id_ = id;
    player_ = player;
}

Ship::~Ship()
{
    int size = cannons_.size();
    for (int i = 0; i < size; i++)
        delete cannons_[i];
}

double Ship::GetHealth() const
{
    return health_;
}

void Ship::IncreaseHealth(double n)
{
    health_ = min(health_ + n, max_health_);
    RoundHealth();
    Update();
}

void Ship::DecreaseHealth(double n, Ship* source)
{
    if (source && source->FindEffect(suck_eff))
        source->IncreaseHealth(n);
    if (FindEffect(shield_eff) && !FindEffect(lock_eff))
    {
        DecreaseEffect(shield_eff, n);
        if (source)
            source->DecreaseHealth(n * shield_rebound_ / 100, nullptr);
    }
    else
    {
        n -= absolute_damage_reduce_ + n * ratio_damage_reduce_ / 100;
        if (n > 0)
            health_ -= n;
    } 
    RoundHealth();
    if (health_ <= 0)
    {
        health_ = 0;
        alive_ = false;
    }
    Update();
    Ban();
    if (GetShipType() == development_ship && n > 0)
    {
        DevelopmentShip* development_ship = dynamic_cast<DevelopmentShip*>(this);
        development_ship->RandomUpdate();
    }
}

void Ship::RoundHealth()
{
    int round_health = round(health_ * 10000);
    health_ = (double)round_health / 10000;
}

void Ship::Ban()
{
    for (Cannon* cannon : cannons_)
        if (health_ < cannon->GetBanHealth())
            cannon->Ban();
}

double Ship::GetMaxHealth() const
{
    return max_health_;
}

int Ship::GetId() const
{
    return id_;
}

bool Ship::GetCanStunned() const
{
    return can_stunned_;
}

int Ship::GetAttackTimes() const
{
    return attack_times_;
}

int Ship::GetDodgeProb() const 
{
    return dodge_prob_;
}

int Ship::GetHealHealth() const 
{
    return heal_health_;
}

int Ship::GetRatioDamageReduce() const
{
    return ratio_damage_reduce_;
}

vector<Cannon*> Ship::GetCannons() const
{
    return cannons_;
}

vector<Skill*> Ship::GetSkills() const
{
    return skills_;
}

int Ship::GetNumCannons() const
{
    return cannons_.size();
}

int Ship::GetNumSkills() const
{
    return skills_.size();
}

ShipType Ship::GetShipType() const
{
    return ship_type_;
}

bool Ship::IsAlive() const
{
    return alive_;
}

void Ship::SetDead()
{
    alive_ = false;
}

const vector<EffectInfo>& Ship::GetEffects() const
{
    return effects_;
}

int Ship::FindEffect(Effect type) const
{
    auto it = effects_.begin();
    while (it != effects_.end())
    {
        if ((*it).type == type)
            return (*it).time;
        it++;
    }
    return 0;
}

bool Ship::IncreaseEffect(Effect type, int time)
{
    auto it = effects_.begin();
    while (it != effects_.end())
    {
        if ((*it).type == type)
        {
            if (type == specter_eff)
            {
                (*it).time = min((*it).time + time, 5);
                Update();
            }
            else 
                (*it).time += time;
            return true;
        }
        it++;
    }
    
    // not found
    bool has_immune = FindEffect(immune_eff);
    bool has_shield = FindEffect(shield_eff);
    switch (type)
    {
        case shield_eff: case suck_eff: case heal_eff: case fury_eff: case dodge_eff: case hide_eff:
            effects_.push_back(EffectInfo{type, time});
            return true;
        case specter_eff:
            effects_.push_back(EffectInfo{type, time});
            Update();
            return true;
        case burn_eff: case lock_eff:
            if (!has_immune)
            {
                effects_.push_back(EffectInfo{type, time});
                return true;
            }
            return false;
        case stunned_eff:
            if (!has_immune && !has_shield && can_stunned_)
            {
                effects_.push_back(EffectInfo{type, time});
                return true;
            }
            return false;
        case immune_eff:
            effects_.push_back(EffectInfo{type, time});
            DeleteEffect(stunned_eff);
            DeleteEffect(burn_eff);
            DeleteEffect(lock_eff);
            return true;
        default:
            return false;
    }
}

void Ship::DecreaseEffect(Effect type, int time)
{
    auto it = effects_.begin();
    while (it != effects_.end())
    {
        if ((*it).type == type)
        {
            (*it).time = max((*it).time - time, 0);
            if (type == specter_eff)
                Update();
            return;
        }
        it++;
    }
}

void Ship::DeleteEffect(Effect type)
{
    auto it = effects_.begin();
    while (it != effects_.end())
    {
        if ((*it).type == type)
        {
            (*it).time = 0;
            return;
        }
        it++;
    }
}

void Ship::UpdateCurEffect()
{
    auto it = effects_.begin();
    while (it != effects_.end())
    {
        Effect type = (*it).type;
        if (type == heal_eff)
            IncreaseHealth(2);
        if (type == burn_eff)
            DecreaseHealth(FindEffect(burn_eff), nullptr);
        switch (type)
        {
            case stunned_eff: case immune_eff: case suck_eff: case heal_eff: case dodge_eff: case burn_eff:
            case hide_eff:
                (*it).time = max((*it).time - 1, 0);
                break;
            default:
                break;
        }
        it++;
    }
}

void Ship::UpdateOtherEffect()
{
    auto it = effects_.begin();
    while (it != effects_.end())
    {
        if ((*it).type == lock_eff)
            (*it).time = max((*it).time - 1, 0);
        it++;
    }
}

void Ship::CheckEffects()
{
    auto it = effects_.begin();
    while (it != effects_.end())
    {
        if ((*it).time <= 0)
            it = effects_.erase(it);
        else 
            it++;
    }
}

const vector<AccessoryInfo>& Ship::GetAccessories() const
{
    return accessories_;
}

void Ship::AddAccessory(Accessory type)
{
    switch (type)
    {
        case time_bomb_acc:
            if (!FindEffect(immune_eff) && !FindEffect(shield_eff))
                accessories_.push_back(AccessoryInfo{type, 3, "time bomb"});
            break;
        case untime_bomb_acc:
            if (!FindEffect(immune_eff) && !FindEffect(shield_eff))
                accessories_.push_back(AccessoryInfo{type, 0, "untime bomb"});
            break;
        case small_bomb_acc:
            if (!FindEffect(immune_eff) && !FindEffect(shield_eff))
                accessories_.push_back(AccessoryInfo{type, 0, "small bomb"});
            break;
        case big_bomb_acc:
            if (!FindEffect(immune_eff) && !FindEffect(shield_eff))
                accessories_.push_back(AccessoryInfo{type, 0, "big bomb"});
            break;
        default:
            break;
    }
}

void Ship::UpdateAccessory()
{
    auto it = accessories_.begin();
    while (it != accessories_.end())
    {
        Accessory type = (*it).type;
        switch (type)
        {
            case time_bomb_acc:
                (*it).time--;
                if ((*it).time == 0)
                    SetDead();
                it++;
                break;
            case untime_bomb_acc:
            {
                int random = rand() % 100;
                if (random < 30)
                {
                    SetDead();
                    cout << id_ << " \033[1;36m" << name_ << "\033[0m";
                    cout << "'s " << "\033[1;31m" << "untime bomb" << "\033[0m" << " explodes." << endl;
                }
                it++;
                break;
            }
            case small_bomb_acc:
                DecreaseHealth(3, nullptr);
                it++;
                break;
            case big_bomb_acc:
                DecreaseHealth(0.25 * max_health_, nullptr);
                it++;
                break;
            default:
                break;
        }
    }
}

void Ship::DismantleBomb()
{
    auto it = accessories_.begin();
    while (it != accessories_.end())
    {
        Accessory type = (*it).type;
        switch (type)
        {
            case time_bomb_acc: case untime_bomb_acc: case small_bomb_acc: case big_bomb_acc:
            {
                int random = rand() % 100;
                if (random < 75)
                {
                    cout << id_ << " \033[1;36m" << name_ << "\033[0m";
                    cout << "'s " << "\033[1;31m" << (*it).name << "\033[0m" << " is dismantled." << endl;
                    it = accessories_.erase(it);
                }
                else 
                    it++;
                break;
            }
            default:
                break;
        }
    }
}