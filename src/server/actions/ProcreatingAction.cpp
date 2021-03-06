#include "ProcreatingAction.hpp"

namespace server {

    ProcreatingAction::ProcreatingAction(int priority, common::Creature & creature, common::MapObject& object):
        Action(priority, creature, object)
    {
    }
    bool ProcreatingAction::perform(double time_interval)
    {
        common::Creature &another = dynamic_cast<common::Creature &>(object_);
        if(!creature_.isHungry() && !creature_.isThirsty() && !creature_.isTired() && creature_.getTimeToProcreate() == 0 &&
           !another.isHungry() && !another.isThirsty() && !another.isTired() && another.getTimeToProcreate() == 0 &&
            creature_.hasOppositeSex(another))
        {
            if(creature_.getDistance(object_) < DISTANCE_TO_ASSUME_TARGET_ACHIEVED) // cel osiagniety
            {
                creature_.startProcreating(&another);
                another.startProcreating(&creature_);
                return true;
            }
            else
            {
                creature_.partiallyTurnAndMoveToObject(object_, creature_.getSpeed() * time_interval / SPEED_FACTOR_FOR_MOVING, creature_.getSpeed() * time_interval / SPEED_FACTOR_FOR_ROTATING );
                //object_.partiallyTurnAndMoveToObject(creature_, object_.getSpeed() * time_interval / 2000, object_.getSpeed() * time_interval / 18000);
                return true;
            }
        }
        return false;
    }

} // namespace server
