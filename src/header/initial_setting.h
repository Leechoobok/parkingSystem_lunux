#pragma once
#include "parking_status.h"

class initial_setting : public Parking_Status{
public:
    void setInitial(Parking_Status &ref_spot,int number);

    void showCurrentStatus(Parking_Status &spot);

    void parkingTest(int random);
};
