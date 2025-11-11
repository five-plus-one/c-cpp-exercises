#include<iostream>
using namespace std;
int a[200]={};
int cnt = 0;
void cal(char from,char to){
    for(int i=from;i<=to;i++){
        cnt+=(a[i]>0);
    }
}
int main(){
    char ch;
    while((ch = getchar())!=EOF){
        a[ch]++;
    }
    cal('0','9');
    cal('a','z');
    cal('A','Z');
    printf("%d",cnt);
    return 0;
}