#include<stdio.h>
int main(void){
    int a,b;//定义整数a,b
    long long sumnum=0; //定义求和值，涉及到平方之和，为防止超出范围，故使用long long
    printf("请输入两个正整数a,b(a<b),用空格隔开\n");//打印提示
    scanf("%d %d",&a,&b);//输入数据
    for(int i=a;i<=b;i++){ //将i从a到b之间遍历
        sumnum+=i*i; //总和加上i的平方
    }
    printf("答案是:%lld\n",sumnum);//输出
    return 0;
}