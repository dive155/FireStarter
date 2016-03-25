#ifndef TRESPASCLASS_H
#define TRESPASCLASS_H
#include <roomclass.h>
class RoomClass;

class TresPasClass
{
protected:
    RoomClass* room;
public:
    TresPasClass();
    void setRoom(RoomClass* theRoom);
    void toggle(int set);
    bool isOn();
    bool intruderDetected();
private:
    bool active;
};

#endif // TRESPASCLASS_H
