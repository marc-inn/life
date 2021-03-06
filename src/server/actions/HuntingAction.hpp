#ifndef SERVER_HUNTINGACTION_HPP
#define SERVER_HUNTINGACTION_HPP

#include "Action.hpp"
#include "../../const.h"
namespace server {

class HuntingAction : public server::Action
{
public:
    virtual~HuntingAction(){};
    HuntingAction(int priority, common::Creature & creature, common::MapObject& object);
    virtual bool perform(double time_interval);
};

} // namespace server

#endif // SERVER_HUNTINGACTION_HPP
