//WA 为啥？精度问题，考虑不周全
#include<iostream>
#include<cmath>
using namespace std;
double S,r,r1,r2;
int count,T;
int main(){
    while(cin>>S){
        
        r=sqrt(S);
        r1 = floor(r);
        count = 0;
        if(r1 == r){
             count+=4;//4个顶点
        }
        for(int i=1;i<r1;i++){
            r2 = sqrt(r*r-i*i);
            if(ceil(r2)==r2){
                count+=4;
            }
        }
        printf("%d\n",count);
    }
}