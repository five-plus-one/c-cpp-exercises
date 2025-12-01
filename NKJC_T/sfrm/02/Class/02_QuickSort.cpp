#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n,a[N];
void quicksort(int l,int r){
    int i=l,j = r;
    int mid = (l+r)/2;
    int x = a[mid];
    while(i<=j){
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;j--;
        }
        if(l<j) quicksort(l,j);
        if(i<r) quicksort(i,r);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    quicksort(1,n);
    for(int i=1;i<=n;i++){
        printf("%d\n",a[i]);
    }
}