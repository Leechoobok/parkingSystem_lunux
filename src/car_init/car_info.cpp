#include "../header/car.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

car_info ::car_info(){}

car_info :: ~car_info(){
    // cout<<"car 객체 소멸함"<<endl;
}

string car_info :: getNumber(){
    return number;
}

string car_info :: getLocation(){
    return location;
}

string car_info :: getEntranceTime(){
    return entranceTime;
}

void car_info :: setNumber(string number){
    this->number=number;
}

void car_info :: setLocation(string location){
    this->location=location;
}

void car_info :: setEntranceTime(string entranceTime){
    this->entranceTime=entranceTime;
}