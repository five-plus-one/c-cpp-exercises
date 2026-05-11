#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int h1,m1,h2,m2,ans;
    scanf("%d:%d",&h1,&m1);
    scanf("%d:%d",&h2,&m2);
    if(h1 > 21){
        ans = (24 - h1 + h2) * 60 + m2 - m1;
    }else{
        ans = (h2 - h1) * 60 + m2 - m1;
    }
    printf("%d\n",ans);
}