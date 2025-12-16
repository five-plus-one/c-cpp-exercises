#include<stdio.h>
void swap(int *p1,int *p2){ //定义swap函数，用于使用指针交换两个整数的值
    printf("交换前指针变量的值p1,p2分别为%p,%p\n",p1,p2); //输出交换前指针变量p1,p2的值
    printf("交换前指针变量的地址p1,p2分别为%p,%p\n",&p1,&p2); //输出交换前指针变量p1,p2的地址
    int tmp = *p1; //定义临时变量，为指针p1指向的值
    *p1 = *p2; //将p1指向赋值为p2指向的值
    *p2 = tmp; //将p2的指向赋值为临时变量
    printf("交换后指针变量的值p1,p2分别为%p,%p\n",p1,p2); //输出交换后的指针变量p1,p2的值
    printf("交换后指针变量的地址p1,p2分别为%p,%p\n",&p1,&p2); //输出交换后指针变量p1,p2的地址
    return;//结束交换函数
}
int main(){
    int a, b;//定义两个变量a,b
    printf("请输入两个数a,b\n");//打印提示
    scanf("%d %d",&a,&b); //输入a,b
    printf("交换前整数a,b的地址分别为%p,%p\n",&a,&b); //输出交换前整数a,b的地址
    swap(&a,&b); //调用交换函数交换a,b，传入a,b的指针
    printf("交换后整数a,b的地址分别为%p,%p\n",&a,&b); //输出交换后整数a,b的地址
    printf("交换后ab两数分别为%d %d\n",a,b); //输出交换后整数a,b的值
    return 0;//结束程序
}