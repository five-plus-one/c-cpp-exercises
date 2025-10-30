#include<iostream>
#include<cstdio>
using namespace std;
double up,down,height;
int main(){
    cin>>up>>down>>height;
    printf("%.3f",(up+down)*height/2);
}