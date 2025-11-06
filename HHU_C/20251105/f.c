#include<stdio.h>
int issxh(int n){
    int x = n/100;
    int y = n/10%10;
    int z = n%10;
    if(n == x*x*x +y*y*y + z*z*z){
        return 1;
    }else {
        return 0;
    }
}
int main(void){
    for(int i=100;i<1000;i++){
        if(issxh(i)){
            printf("%d\n",i);
        }
    }
    return 0;
}