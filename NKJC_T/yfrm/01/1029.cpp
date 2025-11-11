#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double a,b,c,p;
int main(){
    cin>>a>>b>>c;
    p=(a+b+c)/2 ;
    printf("circumference=%.2f area=%.2f",a+b+c,sqrt(p*(p-a)*(p-b)*(p-c)));
}