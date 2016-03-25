#ifndef FIREEXTCLASS_H
#define FIREEXTCLASS_H
#include <roomclass.h>
class RoomClass;

class FireExtClass
{
public:
    FireExtClass();
private:
    bool active;
    bool sprinkling;
protected:
    RoomClass* room;
public:
    void setRoom(RoomClass* theRoom);
    bool fireDetected();
    void activateSprinklers(int set);
    void toggle(int set);
    bool isOn();
    bool isSprinkling();


};

#endif // FIREEXTCLASS_H
