#include<iostream>
#include<cmath>
using namespace std;
long long S,r,count,r2;
int main(){
    while(cin>>S){
        count =0;
        r = (long long)(sqrt(S));//实际上是向下取整的r
        if(r * r ==S && r>=1){
            count+=4;//四个轴上的点
        }
        if(r>=1){
            for(long long i=1;i<=r;i++){
                r2 = (long long)(sqrt(S-i*i));
                if(r2*r2+i*i==S){
                    if(i<r || (i==r && r*r!=S)){
                    count+=4;}
                }
            }
        }
        printf("%lld\n",count);
    }
}