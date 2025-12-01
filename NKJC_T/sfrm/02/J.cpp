#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
using ll = long long;
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}
const int N = 5*10e6+10;
int T,k,n,a[N];
int solve(int l,int r,int k){
    if(l==r) return a[k];
    int mid = (l+r)/2;
    int x = a[mid];
    int i = l, j = r;
    while( i<=j ){
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        if( i<= j){
            swap(a[i],a[j]);
            i++;j--;
        }
    }
    if(k<=j) return solve(l,j,k);
    if(k>=i) return solve(i,r,k);
    return a[k];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    T = read();
    while(T--){
        n = read();
        k = read();
        for(int i=1;i<=n;i++){
            a[i] = read();
        }
        int ans = solve(1,n,k);
        cout<<ans<<endl;
    }
}