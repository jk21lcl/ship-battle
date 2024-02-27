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

    stunned_ = 0;
    shield_health_ = 0;
    immune_ = 0;
    suck_ = 0;
    heal_ = 0;
    fury_ = 0;
    dodge_ = 0;
    burn_ = 0;
    hide_ = 0;
    lock_ = 0;
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
    if (source && source->IsSuck())
        source->IncreaseHealth(n);
    if (shield_health_ && !IsLock())
    {
        shield_health_ -= n;
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
    if (shield_health_ <= 0)
        shield_health_ = 0;
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

int Ship::GetStunned() const
{
    return stunned_;
}

bool Ship::IsStunned() const
{
    return stunned_;
}

bool Ship::IncreaseStun(int n)
{
    if (n < 0)
    {
        stunned_ += n;
        return true;
    }
    if (!shield_health_ && !immune_ && can_stunned_)
    {
        stunned_ += n;
        return true;
    }
    return false;
}

int Ship::GetShieldHealth() const
{
    return shield_health_;
}

void Ship::IncreaseShieldHealth(int n)
{
    shield_health_ += n;
}

bool Ship::HasShield() const
{
    return shield_health_ != 0;
}

int Ship::GetImmune() const
{
    return immune_;
}

bool Ship::IsImmune() const
{
    return immune_;
}

void Ship::IncreaseImmune(int n)
{
    immune_ += n;
    stunned_ = 0;
    burn_ = 0;
    lock_ = 0;
}

int Ship::GetSuck() const
{
    return suck_;
}

bool Ship::IsSuck() const
{
    return suck_;
}

void Ship::IncreaseSuck(int n)
{
    suck_ += n;
}

int Ship::GetHeal() const
{
    return heal_;
}

bool Ship::IsHeal() const
{
    return heal_;
}

void Ship::IncreaseHeal(int n)
{
    heal_ += n;
}

int Ship::GetFury() const
{
    return fury_;
}

bool Ship::IsFury() const
{
    return fury_;
}

void Ship::IncreaseFury(int n)
{
    fury_ += n;
}

int Ship::GetDodge() const
{
    return dodge_;
}

bool Ship::IsDodge() const
{
    return dodge_;
}

void Ship::IncreaseDodge(int n)
{
    dodge_ += n;
}

int Ship::GetBurn() const
{
    return burn_;
}

bool Ship::IsBurn() const
{
    return burn_;
}

void Ship::IncreaseBurn(int n)
{
    if (!immune_)
        burn_ += n;
}

int Ship::GetHide() const
{
    return hide_;
}

bool Ship::IsHide() const
{
    return hide_;
}

void Ship::IncreaseHide(int n)
{
    hide_ += n;
}

int Ship::GetLock() const
{
    return lock_;
}

bool Ship::IsLock() const
{
    return lock_;
}

void Ship::IncreaseLock(int n)
{
    if (!IsImmune())
        lock_ += n;
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
            if (!immune_ && !shield_health_)
                accessories_.push_back(AccessoryInfo{type, 3, "time bomb"});
            break;
        case untime_bomb_acc:
            if (!immune_ && !shield_health_)
                accessories_.push_back(AccessoryInfo{type, 0, "untime bomb"});
            break;
        case small_bomb_acc:
            if (!immune_ && !shield_health_)
                accessories_.push_back(AccessoryInfo{type, 0, "small bomb"});
            break;
        case big_bomb_acc:
            if (!immune_ && !shield_health_)
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