#pragma once
#include <string>
using namespace std;

class car_info{
private:
    string number;
    string location;
    string entranceTime;

public:
    car_info();
    virtual ~car_info();

    string getNumber();
    string getLocation();
    string getEntranceTime();
    
    void setNumber(string number);
    void setLocation(string location);
    void setEntranceTime(string entranceTime);

    
};
