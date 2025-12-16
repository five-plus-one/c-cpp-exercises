#include<stdio.h>
void reverselist(int *p,int n){ //反转数组函数，包括数组起始指针和数组的长度n
    int i = 0; //初始化临时变量i为0，接下来将反转i和n-i-1
    while(i<=n-i-1){ //在i<=n-i-1的时候，循环执行翻转
        int tmp = *(p+i); //临时变量选取数组i项的值
        *(p+i) = *(p+n-i-1); //利用指针指向数组第i项，将其赋值为数组第n-i-1项的值
        *(p+n-i-1) = tmp; //利用指针指向数组第n-i-1项，将其赋值为临时值
        i++; //i自增
    }
    return;//结束翻转函数
}
int main(){
    int a[6]; //定义数组
    printf("请输入一个6个整数的数组\n");//打印提示
    for(int i=0;i<6;i++){ //i遍历从0到5
        scanf("%d",&a[i]); //输入a[i]
    }
    reverselist(a,6); //执行函数，翻转数组
    printf("反转后的数组为"); //打印提示
    for(int i=0;i<6;i++){ //遍历i从0到5
        printf(" %d",a[i]); //输出a[i]项
    }
    return 0; //结束程序
}