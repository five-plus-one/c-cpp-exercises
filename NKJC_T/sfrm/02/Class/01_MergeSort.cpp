#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int a[N],b[N],n;
void mergeparts(int l1,int r1,int l2,int r2){
    int len = r1-l1+2+r2-l2;
    int p = l1,q=l2;
    for(int i=1;i<=len;i++){
        if( q>r2 ||(q<=r2 && p<=r1 && a[p]<a[q])){
            b[i] = a[p];
            p++;
        }else{
            b[i] = a[q];
            q++;
        }
    }
    int pos = 1;
    for(int i=l1;i<=r1;i++){
        a[i]=b[pos];
        pos++;
    }
    for(int i=l2;i<=r2;i++){
        a[i]=b[pos];
        pos++;
    }
    return;
}
void mergesort(int l,int r){
    if(l == r) return;
    int mid = (l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    mergeparts(l,mid,mid+1,r);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(1,n);
    for(int i=1;i<=n;i++){
        printf("%d\n",a[i]);
    }
}