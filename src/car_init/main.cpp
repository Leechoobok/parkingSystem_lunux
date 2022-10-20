#include "../header/car.h"
// #include "car.cpp"
// #include "car_info.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;
int main(){
    cout<<"start"<<endl;
    vector<car> spot;
    int count =0;
    
    
    
    while(true){
        if(spot.size()==32) break;
        car car;
        count +=1;
        car.carEnterRand();
        spot.push_back(car);

        cout<<"spot : "<<count<<"]"
            <<car.getEntranceTime()<<"\t"
            <<car.getLocation()<<"\t"
            <<car.getNumber()<<"\t"<<endl;
        sleep(2);
    }
    
}