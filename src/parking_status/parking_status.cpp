#include "../header/initial_setting.h"
#include <string>
#include <iostream>
using namespace std;

Parking_Status :: Parking_Status(){
}
Parking_Status :: ~Parking_Status(){};

bool Parking_Status ::isCarExist(){
    return carexist;
}

void Parking_Status :: carInput(){
    carexist=true;
}

string Parking_Status :: getcarLocation(){
    return location;
}

void Parking_Status :: setCarnumber(string carnumber){
    this->carnumber=carnumber;
}

string Parking_Status :: getCarnumber(){
    return carnumber;
}

string Parking_Status :: getCarStatus(){
    bool status = carexist;
    if(status==NO)  return string("NO");
    else return string("YES");
}


void Parking_Status :: setLocation(string location){
    this->location=location;
}

void Parking_Status :: setCarExist(bool flag){
    carexist=flag;
}




