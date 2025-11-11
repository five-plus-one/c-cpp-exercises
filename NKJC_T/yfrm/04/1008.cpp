#include<iostream>
#include<cstdio>
using namespace std;
const int  N = 1e3+10;
int n,num[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    int count = 0;
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(num[j]<num[i]){
                count++;
            }
        }
    }
    cout<<count;
}