#include<iostream>
#include<cstdio>
using namespace std;
const int N = 55;
int n,m,cnt,cnt_min;
int white[N],blue[N],red[N],white_qzh[N],blue_qzh[N],red_qzh[N];
char c;
int main(){
    scanf("%d %d",&n,&m);
    cnt_min = n * m;
    white_qzh[0] = 0;
    blue_qzh[0] = 0;
    red_qzh[0] = 0;
    for(int i=1;i<=n;i++){
        white[i] = 0;
        blue[i] = 0;
        red[i] = 0;
        for(int j=1;j<=m;j++){
            scanf(" %c",&c);
            if(c == 'W') white[i]++;
            else if(c == 'B') blue[i]++;
            else if(c == 'R') red[i]++;
        }
        white_qzh[i] = white_qzh[i-1] + white[i];
        blue_qzh[i] = blue_qzh[i-1] + blue[i];
        red_qzh[i] = red_qzh[i-1] + red[i];
    }
    // i代表蓝色开始的行数,j代表红色开始行数,(i-1)行白，(j-i)行蓝,(n-j+1)行红
    for(int i=2;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            cnt = ((i-1)*m - white_qzh[i-1]) + ((j-i)*m - (blue_qzh[j-1] - blue_qzh[i-1])) + ((n-j+1)*m - (red_qzh[n] - red_qzh[j-1]));
            cnt_min = min(cnt_min,cnt);
            // cout<<i<<' '<<j<<' '<<cnt<<endl;
        }
    }
    printf("%d\n",cnt_min);
}