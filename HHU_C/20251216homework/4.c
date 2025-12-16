#include<stdio.h>
void modify_array(int *p,int n,int opnum){ //定义修改数组函数，传参为：数组初始地址，数组大小，操作数（加上的数）
    while(n--){ //重复执行 n 次
        *p += opnum; //将当前p的指向加上opnum
        p++; //将p指向数组下一个函数
    }
    return; //结束修改数组函数
}
void printlist(int *p,int n){ //打印数组函数，传参包括：数组初始地址，数组大小
    while(n--){ //重复执行n次
        printf(" %d",*p); //打印当前p的指向值
        p++; //p指向数组下一个元素
    }
    printf("\n"); //打印换行符
    return; //结束打印数组函数
}
int main(){
    int a[5]; //定义大小为5的数组
    printf("请输入一个5个整数的数组\n"); //打印提示
    for(int i=0;i<5;i++){ //i遍历从0到4
        scanf("%d",&a[i]); //输入a[i]
    }
    printf("修改前的数组为"); //打印提示
    printlist(a,5); //打印修改前的数组
    modify_array(a,5,5); //执行数组修改函数，其中操作数为5，即所有元素加上5
    printf("修改后的数组为"); //打印提示
    printlist(a,5); //打印修改后的数组
    return 0; //结束程序
}