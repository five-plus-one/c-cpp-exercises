#include<iostream>
using namespace std;
int a,b,day,hour;

int main(){
    day = 0;hour = 0;
    for(int i=1;i<=7;i++){
        cin>>a>>b;
        if(a+b>8 && a+b>hour){
            hour = a+b;day = i;
        }
    }
    cout<<day;
    return 0;
}