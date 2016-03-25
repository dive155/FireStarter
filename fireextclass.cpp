#include "fireextclass.h"

FireExtClass::FireExtClass()
{
    active = false;
    sprinkling = false;
}

void FireExtClass::setRoom(RoomClass *theRoom)
{
    room = theRoom;
}

bool FireExtClass::fireDetected()
{
    if (room->isBurning() && active == true)
    {
        return true;
    }
    else {
        return false;
    }
}

void FireExtClass::activateSprinklers(int set)
{
    sprinkling = set;
}

void FireExtClass::toggle(int set)
{
    active = set;
}

bool FireExtClass::isOn()
{
    return active;
}

bool FireExtClass::isSprinkling()
{
    return sprinkling;
}

