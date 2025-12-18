#include<stdio.h>
void printn(int n,char ch){ //自定义函数，用于输出n个ch
    while(n--) printf("%c",ch); //重复执行n次，输出ch
    return; //结束自定义函数
}
void pyramid(int n,char ch){ //自定义函数，用于打印n行，组成字符为ch的金字塔
    for(int i=1;i<=n;i++){ //i作为行数，从1到n遍历
        printn(n-i,' '); //先调用自定义函数，打印n-i个空格
        for(int j=1;j<=i;j++){ //然后打印i个字符，让j从1到i遍历，重复执行i次
            printf("%c ",ch); //打印字符+空格
        }
        printf("\n");//换行
    }
    return;//结束自定义函数
}
int main(void){
    int n;//定义变量n
    char ch; //定义字符变量ch
    scanf("%d %c",&n,&ch); //输入n和ch
    pyramid(n,ch); //调用自定义函数打印n行组成字符为ch的金字塔
    return 0; //结束程序
}