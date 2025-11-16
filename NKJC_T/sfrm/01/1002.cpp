#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
bool szh = true;
void print(int n,int x){
    if(n!=0){
        if(n>0 && szh == false){
            printf("+");
        }
        if(fabs(n)!=1 || x==0){
            printf("%d",n);
        }else if(n==-1){
            printf("-");
        }
        if(x==1){
            printf("x");
        }else if(x>1){
            printf("x^%d",x);
        }
    }
    if(n==0 &&x==0&& szh == true){
        printf("0");
    }
    if(n!=0){
        szh = false;
    }
    return;
}
int main(){
    int n,xs[110];
    scanf("%d",&n);
    for(int i=n;i>=0;i--){
        scanf("%d",&xs[i]);
    }
    szh = true;
    for(int i=n;i>=0;i--){
        print(xs[i],i);
    }
}