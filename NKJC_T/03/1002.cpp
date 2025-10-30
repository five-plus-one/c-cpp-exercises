#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int i,n,j,num=0;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            num++;
            printf("%4d",num);
        }
        printf("\n");
    }
}