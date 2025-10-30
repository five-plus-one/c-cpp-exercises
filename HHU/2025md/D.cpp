#include<iostream>
using namespace std;
int main(){
    int A,B,C,D,a,b,c,d,e;
    long long cnt;
    scanf("%d%d%d%d%d%d%d%d%d",&A,&B,&C,&D,&a,&b,&c,&d,&e);
    if(D<=520){
        cnt = (520-D)*e + (D-C)*d +(C-B)*c + (B-A)*b + A*a;
    }else if(C<=520){
        cnt = (520-C)*d +(C-B)*c + (B-A)*b + A*a;
    }else if(B<=520){
        cnt = (520-B)*c + (B-A)*b + A*a;
    }else if(A<=520){
        cnt = (520-A)*b + A*a;
    }else{
        cnt = 520*a;
    }
    printf("%lld",cnt);
    return 0;
}