#include<stdio.h>
int main(void){
    int num=0,cnt=0,sum=0;//定义变量，当前输入数，输入个数，总和
    printf("请输入一系列整数,输入负数时停止\n"); //提示
    while(1){ //无限循环
        scanf("%d",&num);
        if(num<0) break; //如果输入负数，跳出循环
        cnt++; //输入个数增加
        sum+=num; //总和增加
    }
    double average = sum*1.0/cnt; //求平均值
    printf("个数:%d,总和:%d,平均值:%.2f\n",cnt,sum,average);//输出
    return 0;
}