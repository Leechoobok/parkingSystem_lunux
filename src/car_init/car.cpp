#include"../header/car.h"
#include<string>
#include<time.h>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

car :: car(){
    setNumber("None");
    setLocation("None");
    setEntranceTime("Noen");
}
car :: ~car(){}

void car :: carEnterRand(){

    /*현재시간 입력함수*/
    setEntranceTime(CurrentEntranceTime());
    /*임의차량번호 입력 함수*/
    setNumber(RandNumber());

    /*임의차량위치 입력함수*/
    setLocation(RandLocation());
    
}

string car ::  CurrentEntranceTime(){
    /*현재시간 입력 함수 */
    time_t timer;
    struct tm* t;
    timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
    t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기
    
    string year("2022");
    string month(to_string(t->tm_mon));
    string day(to_string(t->tm_mday));
    string hour(to_string(t->tm_hour));
    string min(to_string(t->tm_min));
    string sec(to_string(t->tm_sec));

    string entranceTime(year+"년"+month+"월"+day+"일"+hour+"시"+min+"분"+sec+"초");
    return entranceTime;

}

string car ::  RandNumber(){
    string number(
        "가"
        +to_string(rand()%10)
        +to_string(rand()%10)
        +to_string(rand()%10)
        +to_string(rand()%10));

    return number;
}

string car :: RandLocation(){
    string location;
    string frontNum;
    

    std::vector<int> spot;    //vetor선언
    std::vector<int>::iterator itr_spot;  //vector 을 가리키는iterator선언
        /*벡터사이즈는 32로제한*/
        if(spot.size()==32) return "남은자리가 없습니다.";

    /*벡터의 뒤에서부터 0~32 임의의값 입력*/
        spot.push_back(rand()%32);    

        /*중복된값 색출 */
        itr_spot=spot.begin();
        for(int i=0;i<(int)spot.size();i++){
            if(spot.at(i)==(int)*itr_spot) spot.pop_back(); //만약 입력된값이 이전에 있으면 입력된값 제거
            else itr_spot +=1;
        }

    /*자리번호를 PXX로 만들기*/
   
        //if((int)*spot.end()<10) location = "P0"+to_string(*spot.end());
        
        //else
        location="P"+to_string(*spot.end());
        return location;
        
    

    
}
