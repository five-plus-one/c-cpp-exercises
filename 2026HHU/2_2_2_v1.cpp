#include<iostream>
#include<cstdio>
using namespace std;
void printn(int n){
    if(n == 0){
        printf("0");
        return;
    }
    int i =0;
    while((1LL<<(i+1))<=n){
        i++;
    }
    if((1LL<<i)==2) printf("2");
    else{
        printf("2(");
        printn(i);
        printf(")");
    }
    if(n - (1LL<<i)>0){
        printf("+");
        printn(n-(1LL<<i));
    }
}
int main(){
    int n;
    scanf("%d",&n);
    printn(n);
    return 0;
}