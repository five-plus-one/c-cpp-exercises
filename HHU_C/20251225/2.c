#include<stdio.h>
int max(int a,int b){ //自定义函数，用于获取最大值
    if(a<b) return b;
    else return a;
}
int main(){
    int n,a[11][4]; //定义变量
    scanf("%d",&n); //输入n
    for(int i=0;i<n;i++){ //遍历i从0到n-1
        int sumscore = 0;  //临时变量总分归为0
        for(int j=0;j<4;j++){ //遍历j从0到3
            scanf("%d",&a[i][j]); //输入分数
            sumscore+=a[i][j]; //总分加和
            if(i==0){ //如果是第0项，那么将a[10][x](存储的最大值)设为第0项，否则取两者最大值
                a[10][j] = a[0][j];
            }else{
                a[10][j] = max(a[10][j],a[i][j]);
            }
        }
        printf("%d\n",sumscore); //打印总分
    }
    for(int j=0;j<4;j++){
        printf("%d ",a[10][j]); //打印最高分
    }
    return 0;
}