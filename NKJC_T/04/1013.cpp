#include<iostream>
using namespace std;
const int N = 2010;
int n,a[N]={0};
int main(){
    cin>>n;
    for(int i=2;i*i<n;i++){
        for(int j=2;j*i<=n;j++){
            a[j*i] = 1;
        }
    }
    for(int i=2;i<=n;i++){
        if(!a[i]){printf("%d ",i);}
    }
}