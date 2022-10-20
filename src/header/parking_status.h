#pragma once
#include <string>

#define NO      false
#define YES     true
using namespace std;

class Parking_Status{
private:
    bool carexist;      //차의 존재유무
    string location;    // 주차장위치
    string carnumber;   //주차된차의 번호

public:
    bool isCarExist();  //carexist를 확인

    void carInput();    //차량존재유무를 true로 입력

    string getcarLocation();    //오브젝트의 주차장위치를 반환
    string getCarnumber();      //오브젝트의 차량번호를 반환
    string getCarStatus();      //오브젝트의 현재 차량이 주차되어있는지 아닌지를 반환

    void setLocation(string location);      //지정된 주차장위치를 입력
    void setCarnumber(string carnumber);    //지정된 차량번호를 입력
    void setCarExist(bool flag);        //지정된 차량유무를 입력


//    void setInitial(int spots_number);


    Parking_Status();
    ~Parking_Status();

};





