#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
int main(void){
    for(int i=1;i<=5;i++){
        srand((int)time(0));
        int magic = rand()%100 +1;
        printf("%d",magic);
    }
}