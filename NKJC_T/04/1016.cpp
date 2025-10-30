#include<iostream>
using namespace std;
using ll = long long;
ll a[36][36];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(i == 1 && j==1){a[1][1]=1;}else{
            a[i][j]=a[i-1][j-1]+a[i-1][j];}
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}