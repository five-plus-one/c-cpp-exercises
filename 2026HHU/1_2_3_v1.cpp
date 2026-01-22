#include<iostream>
using namespace std;
const int N = 5 * 10e5;
using ll = long long;
int a[N],n,tmp[N];
ll cnt = 0;
void merge_sort(int l,int r){
    if(l>=r) return;
    int mid = (l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]){
            tmp[k++] = a[i++];
        }else{
            // a[i] > a[j] , 那么 a[j]和 i到mid的所有元素都是逆序对
            tmp[k++] = a[j++];
            cnt += mid - i +1;
        }
    }
    while(i<=mid){
        tmp[k++] = a[i++];
    }
    while(j<=r){
        tmp[k++] = a[j++];
    }
    for(int i = l;i<=r;i++){
        a[i] = tmp[i];
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cnt = 0;
    merge_sort(0,n-1);
    cout<<cnt<<endl;
    return 0;
}