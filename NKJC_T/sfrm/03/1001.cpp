#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2*1e5+10;
int a[N],n,q,l,r;
int ef1(int x){
    int l=1,r=n;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]>=x){
            r = mid -1;
        }else{
            l = mid +1;
        }
    }
    return l;
}
int ef2(int x){
    int l=1,r=n;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]<=x){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return r;
}
int solve(int p,int q){
    return (ef2(q) - ef1(p) + 1);
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&l,&r);
        printf("%d\n",solve(l,r));
    }
    return 0;
}