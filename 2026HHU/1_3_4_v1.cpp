#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[30],n,r;
int main(){
    scanf("%d %d",&n,&r);
    for(int i=r+1;i<=n;i++) a[i] = 1;
    do{
        for(int j=1;j<=n;j++){
            if(a[j] == 0) printf("%3d",j);
        }
        printf("\n");
    }while(next_permutation(a+1,a+1+n));
    return 0;
}