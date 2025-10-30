#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const long long N = 8000000+10;

int a[N],n,maxdiff = 0;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        if(a[i+1]-a[i]>maxdiff){
            maxdiff = a[i+1]-a[i];
        }
    }
    printf("%d",maxdiff);

}