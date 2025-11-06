#include<stdio.h>

int isrpime(int n){
    if(n==0||n==1){
        return 0;
    }
    int i =2;
    while(i*i<=n){
        if(n%i==0){
            return 0;
        }
        i++;
    }
    return 1;
}
int main(void){
    int k =0;
    for(int i=1;i<=1000;i++){
        if(isrpime(i)){
            printf("%5d",i);
            k++;
            if(k%5==0){
            printf("\n");
        }
        }
        
    }
}