#include "roomclass.h"

RoomClass::RoomClass()
{
    burning = 0;
    intruded = 0;
}

bool RoomClass::isBurning()
{
    return burning;
}

bool RoomClass::isIntruded()
{
    return intruded;
}

void RoomClass::setOnFire(int set)
{
    burning = set;
}

void RoomClass::intrude(int set)
{
    intruded = set;
}

