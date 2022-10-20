#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;

class Car{
private:
    string spot;
    string license_plate;
    int into_ptimeH, into_ptimeM;
    int fare;
    vector<string> defualt_spot;
    vector<string> default_plate;
public:
    Car(string spot, string license_plate, int into_ptimeH, int into_ptimeM);
    void writeData();
    void readData();
    int readData(string str);
    void deleteData(string str);
    int rate_check();
    string GetLicense_plate();
    int GetParkingtime();
    int Getinto_timeH();
    int Getinto_timeM();
    string Get_Spot();
    string Get_default_Spot(int i);
    string Get_default_License_plate(int i);
    int Get_Count();
    void Set_car(string license_plate);
    void Set_Spot(string spot);

    ~Car();
};
