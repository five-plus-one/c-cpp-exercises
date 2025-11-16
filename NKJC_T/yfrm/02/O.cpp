#include<iostream>
using namespace std;

int main(){
    int YYYY,MM;
    scanf("%4d%2d",&YYYY,&MM);
    if(MM>=3&&MM<=5){
        cout<<"spring";
    }else if(6<=MM && MM <=8){
        cout<<"summer";
    }else if(9<=MM && MM<=11){
        cout<<"autumn";
    }else {
        cout<<"winter";
    }
    return 0;
}