#include<stdio.h>
int main(void){
    int year = 2023,books = 100; //初始化，2023年底有100本图书
    while(books<=500){//要求超出500本，所以<=500本的时候维持循环状态
        year++;//下一年
        if(year %4 ==0){ //若年份是4的倍数
            books+=50; //书增加50本
        }else if(year %2 ==1){ //若年份是奇数
            books+=30; //增加30本
        }else{//其他情况
            books+=40; //增加40本
        }
    }
    printf("最早第%d年图书总量能超过500本,当年图书总量为%d。\n",year,books); //输出
    return 0;
}