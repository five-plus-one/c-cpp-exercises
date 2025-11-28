//80WA
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string a[30];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        cout<<a[i];
    }
}