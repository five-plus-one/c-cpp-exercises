#include<iostream>
#include<algorithm> //next_permutation的用法
using namespace std;
int a[10],n,total;
int main(){
    total = 1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        a[i] = i;
        total *=i;
    }
    for(int i=1;i<=total;i++){
        for(int j=1;j<=n;j++){
            printf("%5d",a[j]);
        }
        printf("\n");
        next_permutation(a+1,a+1+n);
    }
    return 0;
}