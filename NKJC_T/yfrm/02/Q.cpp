#include<iostream>
using namespace std;
bool isRunNian(int n){
    if(n % 400 ==0 || (n%4 ==0 && n%100 !=0)){
        return true;
    }else {
        return false;
    }
}
int getDaysNum(int y,int m){
    if(m == 1||m==3||m==5||m==7||m==8||m==10||m==12){
        return 31;
    }else if(m==2){
        if(isRunNian(y)){
            return 29;
        }else{
            return 28;
        }
    }else {
        return 30;
    }
}
void printDate(int y,int m,int d){
    cout<<y<<"-";
    if(m<10){
        cout<<"0";
    }
    cout<< m <<"-";
    if(d < 10){
        cout<<"0";
    }
    cout<<d;
}
int main(){
    int yyyy,mm,dd;
    scanf("%d-%d-%d",&yyyy,&mm,&dd);
    if(dd>2){
        printDate(yyyy,mm,dd-2);
    }else {
        mm --;
        if(mm == 0){
            mm=12;
            yyyy--;
        }
        dd=getDaysNum(yyyy,mm)-(2-dd);
        printDate(yyyy,mm,dd);
    }
    return 0;
}