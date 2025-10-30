#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        char map[n+10][6];
        bool flag = false;
        for(int i=1;i<=n;i++){
            getchar();//换行符
            map[i][1]=getchar();
            map[i][2]=getchar();
            if(flag == false && map[i][1]=='O'&& map[i][2]=='O'){
                map[i][1]='+';map[i][2]='+';flag = true;
            }
            getchar();//分隔符
            map[i][3]=getchar();
            map[i][4]=getchar();
            if(flag == false && map[i][3]=='O'&& map[i][4]=='O'){
                map[i][3]='+';map[i][4]='+';flag = true;
            }
        }
        if(flag == false){
            printf("NO\n");
        }else{
            printf("YES\n");
            for(int i=1;i<=n;i++){
                printf("%c%c|%c%c\n",map[i][1],map[i][2],map[i][3],map[i][4]);
            }
        }
    }
}