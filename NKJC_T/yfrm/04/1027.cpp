#include<iostream>
#include<cstdio>
using namespace std;
int n,steps,level,x,y,num;
int map[1010][1010];
int main(){
    scanf("%d",&n);
    num = 0;
    for(level = 1;level<=2*n-1;level++){
        if(level<=n){steps=level;}
        else{steps=2*n-level;}
        if(level<=n){
            if(level %2 ==1){
                x=level;y=1;
            }else{
                y=level;x=1;
            }
        }else{
            if(level %2 ==0){
                x=level-n+1;y=n;
            }else{
                y=level-n+1;x=n;
            }
        }
        for(int j=1;j<=steps;j++){
            num++;
            map[x][y] = num;
            if(level % 2 ==1){
                x--;y++;
            }else{
                x++;y--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}