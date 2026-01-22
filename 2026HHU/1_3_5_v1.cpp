// 5plus1 20260122 v1
#include<iostream>
#include<algorithm>

using namespace std;

bool isPrime(int n){
    if(n == 1) return 0;
    int i=2;
    while(i*i<=n){
        if(n%i==0) return 0;
        i++;
    }
    return 1;
}
int a[30],choose[30],n,k;
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=k+1;i<=n;i++) choose[i] = 1;
    int cnt = 0;
    do{
        int sumnum = 0;
        for(int i=1;i<=n;i++) sumnum += (choose[i] ==0) * a[i];
        if(isPrime(sumnum)) cnt++;
    }while(next_permutation(choose+1,choose+1+n));
    cout<<cnt<<endl;
}