#include "trespasclass.h"

TresPasClass::TresPasClass()
{
    active = false;
}

void TresPasClass::setRoom(RoomClass *theRoom)
{
    room = theRoom;
}

void TresPasClass::toggle(int set)
{
    active = set;
}

bool TresPasClass::isOn()
{
    return active;
}

bool TresPasClass::intruderDetected()
{
    if (room->isIntruded() && active == true)
    {
        return true;
    }
    else {
        return false;
    }
}

