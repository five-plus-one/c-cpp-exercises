#include<iostream>
#include<cstdio>
using namespace std;
int a1,a2,a3,a4,a5,a6,a7,a8,a9,dr;
char d,drc;
long long an;

int main(){
    // cout<<int('0');
    scanf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%1c",&a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9,&d);
    an = a1*1+a2*2+a3*3+a4*4+a5*5+a6*6+a7*7+a8*8+a9*9;
    dr = an % 11;
    if(dr == 10){
        drc = 'X';
    }else {
        drc = char(dr+48);
    }

    if(drc == d){
        cout<<"Right";
    }else {
        printf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%1c",a1,a2,a3,a4,a5,a6,a7,a8,a9,drc);
    }

    return 0;
}