#include<stdio.h>
int main(){
    int a[5]; //定义数组
    printf("请依次输入数组的5个元素\n"); //输出提示
    for(int i=0;i<5;i++){ //依次输入5个元素，其中i从0到4遍历
        scanf("%d",&a[i]); //输入a[i]
    }
    int sumnum = 0; //定义求和值并初始化为0
    for(int i=0;i<5;i++){ //i从0到4遍历整个数组
        sumnum += a[i]; //将求和值加上a[i]
    }
    printf("这些元素的和为%d\n",sumnum); //输出结果
    return 0; //结束程序
}