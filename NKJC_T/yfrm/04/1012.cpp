#include<iostream>
using namespace std;
int n,a[60],num;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&num);
    if(num < a[1]){
        printf("%d ",num);
    }
    for(int i=2;i<=n;i++){
        printf("%d ",a[i-1]);
        if(num >= a[i-1] && num<a[i]){
            printf("%d ",num);
        }
    }
    printf("%d ",a[n]);
    if(num >= a[n]){
        printf("%d ",num);
    }
    return 0;
}