#include<stdio.h>

void move(int num,char from,char to,char rest){
    if(num == 0) return;
    move(num-1,from,rest,to);
    printf("move#%d from %c to %c\n",num,from,to);
    move(num-1,rest,to,from);
}
int main(void){
    int n;
    scanf("%d",&n);
    move(n,'A','C','B');
}