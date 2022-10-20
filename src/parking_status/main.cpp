#include "../header/parking_status.h"

#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
int main(){
    
    array<Parking_Status,32>spots;
    for(int i=0; i<(int)spots.size();i++){
        spots[i].setCarExist(NO);
        spots[i].setCarnumber("None");
        spots[i].setLocation("None");
    }

    for(int i=0; i<(int)spots.size();i++){
        cout<<"spot["<<i<<"] : "
            <<spots[i].getCarStatus()<<" "
            <<spots[i].getCarnumber()<<" "
            <<spots[i].getcarLocation()<<" "<<endl;
    }
    
}