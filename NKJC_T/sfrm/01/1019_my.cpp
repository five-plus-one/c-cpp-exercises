#include<iostream>
using namespace std;
int operate1(int ori,int op){
    return (ori ^ op)^(op>>1)^((op<<1)&(15));
}
int operate2(int ori,int op){
    return (ori ^ op);
}
int map[10],map2[10],n,m;
int main(){
    for(int i=1;i<=4;i++){
        int n=0,c;
        for(int j=1;j<=4;j++){
            scanf("%1d",&c);
            n=n*2+c;
        }
        map2[i] = n;
    }
    int cnt = 0;
    for(int op = 0; op<16;op++){ // 针对第一行的操作
        for(int i=1;i<=4;i++){
            map[i] = map2[i];
        }
        map[1] = operate1( map[1],op);
        map[2] = operate2( map[2],op);
        for(int i=2;i<=4;i++){ //从第二行开始，操控使前一行灭掉
            map[i] = operate1(map[i],map[i-1]);
            map[i+1] = operate2(map[i+1],map[i-1]);
        }
        if(map[4] == 0) cnt++;
    }
    if(cnt > 0) printf("YES\n");
    else printf("NO\n");
    return 0;
}