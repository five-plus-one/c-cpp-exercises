#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1010;
int n;
char map[N][N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf(" %c",&map[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--){
            printf("%c",map[j][i]);
        }
        if(i<n){
        printf("\n");}
    }
    return 0;
}