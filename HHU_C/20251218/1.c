#include<stdio.h>
int main(void){
    int n,a[101],cnt=0; //定义变量：n,数组，谷数个数
    scanf("%d",&n); //输入n
    for(int i=0;i<n;i++){ //i遍历0到n-1
        scanf("%d",&a[i]); //输入a[i]
    }
    for(int i=1;i<n-1;i++){ //i从1到n-2遍历（排除端点）
        if(a[i]<a[i-1] && a[i]<a[i+1]) cnt++; //判断是否为谷数，如果是，个数增加
    }
    printf("%d\n",cnt); //输出个数
    return 0; //结束程序
}