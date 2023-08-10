#include "explosive_event.h"
#include "game.h"

ExplosiveEvent::ExplosiveEvent(Cannon* cannon, Ship* source, Ship* target,
                               Ship* splash_tar_1, Ship* splash_tar_2)
{
    event_type_ = explosive_event;
    cannon_ = cannon;
    source_ = source;
    target_ = target;
    splash_tar_1_ = splash_tar_1;
    splash_tar_2_ = splash_tar_2;
}

void ExplosiveEvent::Process()
{
    dynamic_cast<ExplosiveCannon*>(cannon_)->SpecialAttack(source_, target_,
        splash_tar_1_, splash_tar_2_);
}