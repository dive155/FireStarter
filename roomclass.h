#ifndef ROOMCLASS_H
#define ROOMCLASS_H


class RoomClass
{
public:
    RoomClass();
    bool isBurning();
    bool isIntruded();
    void setOnFire(int set);
    void intrude(int set);
private:
    bool burning;
    bool intruded;
};

#endif // ROOMCLASS_H
