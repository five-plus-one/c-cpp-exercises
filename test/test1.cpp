#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int a[10]={[0]=1,[5]=2,[6]=3};
    for(int i=0;i<6;i++) cout<<a[i]<<" ";
    return 0;
}