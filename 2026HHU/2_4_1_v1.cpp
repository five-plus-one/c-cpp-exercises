// 20260129 5plus1 v1
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e6 + 10;
int n,a[N],m,target;
int search(int target,int left,int right){
    if(left > right) return -1;
    int mid = left + (right - left )/2;
    if((a[mid]==target && mid > 1  && a[mid-1]!=target)||a[mid]==target && mid ==1) return mid;
    else if(a[mid] > target || (a[mid]==target && a[mid-1]==target)) return search(target,left,mid-1);
    else return search(target,mid+1,right);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    while(m--){
        scanf("%d",&target);
        printf("%d ",search(target,1,n));
    }
    printf("\n");
}