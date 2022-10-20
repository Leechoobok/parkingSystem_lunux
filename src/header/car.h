#pragma once
#include <string>
#include "car_info.h"
using namespace std;

class car : public car_info{

public:
    car();
    virtual ~car();
    void carEnterRand();    //차량의 number,location,EnterTime이 렌덤하게 입력됩니다.

    string CurrentEntranceTime();
    string RandNumber();
    string RandLocation();

};

