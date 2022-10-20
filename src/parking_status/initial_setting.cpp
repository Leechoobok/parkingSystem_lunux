
#include"../header/initial_setting.h"
#include <iostream>
using namespace std;

void showCurrentStatus(Parking_Status &spot){
    cout<<"car status : "<<spot.getCarStatus()<<"\t"
        <<"car location : "<<spot.getcarLocation()<<"\t"
        <<"car number : "<<spot.getCarnumber()<<endl; 
}

void setInitial(Parking_Status &ref_spot,int number){
    string P("P");
    string XX("0");
    string None("None");
    
    ref_spot.setLocation(P+"0"+to_string(number));
    if(number>=10){
        ref_spot.setLocation(P+to_string(number));
    }
    ref_spot.setCarnumber(None);
    ref_spot.setCarExist(NO);
    
}


void parkingTest(int random,Parking_Status& spot){
    string spot_num ="P"+to_string(random);
   
    if(spot.getcarLocation()==spot_num){
        spot.carInput();
        spot.setCarExist(YES);
        spot.setCarnumber("가1234");
        }    
    
}




