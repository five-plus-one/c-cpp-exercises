#include<iostream>
using namespace std;
const int N = 1010;
int numlist[N]={};
int n,tmpnum,m;
int main(){
    scanf("%d",&n);
    m = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&tmpnum);
        numlist[tmpnum]++;
        if(numlist[tmpnum]==1){
            m++;
        }
    }
    printf("%d\n",m);
    for(int i=1;i<=1000;i++){
        if(numlist[i]>0){
            printf("%d ",i);
        }
    }
}