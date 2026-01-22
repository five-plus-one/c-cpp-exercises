// 5plus1 20260122
#include<iostream>
#include<cstdio>
using namespace std;

int a,b;

bool isPrime(int n){
    int i = 2;
    while(i * i<=n){
        if(n%i==0) return 0;
        i++;
    }
    return 1;
}
void judgeandprint(int n){
    if(n>=a && n<=b && isPrime(n)) printf("%d\n",n);
}
void printnum(int digit){
    if(digit == 1){
        for(int i=a;i<=9;i++){
            judgeandprint(i);
        }
    }else if(digit == 2){
        for(int d1=1;d1<=9;d1+=2){
            int num = d1*10 + d1;
            if(num >b) return;
            judgeandprint(num);
        }
    }else if(digit == 3){
        for(int d1=1;d1<=9;d1+=2){
            for(int d2 = 0;d2<=9;d2++){
                int num = d1*100+d2*10+d1;
                if(num > b) return;
                judgeandprint(num);
            }
        }
    }else if(digit == 4){
        for(int d1 = 1;d1<=9;d1+=2){
            for(int d2 = 0;d2<=9;d2++){
                int num = d1*1e3 + d2*1e2 + d2 * 10 + d1;
                if(num >b) return;
                judgeandprint(num);
            }
        }
    }else if(digit == 5){
        for(int d1 =1;d1<=9;d1+=2){
            for(int d2=0;d2<=9;d2++){
                for(int d3=0;d3<=9;d3++){
                    int num = d1*1e4+d2*1e3+d3*1e2+d2*1e1+d1;
                    if(num>b) return;
                    judgeandprint(num);
                }
            }
        }
    }else if(digit == 6){
        for(int d1 =1;d1<=9;d1+=2){
            for(int d2=0;d2<=9;d2++){
                for(int d3=0;d3<=9;d3++){
                    int num = d1*1e5+d2*1e4+d3*1e3+d3*1e2+d2*1e1+d1;
                    if(num>b) return;
                    judgeandprint(num);
                }
            }
        }
    }else if(digit == 7){
        for(int d1 =1;d1<=9;d1+=2){
            for(int d2=0;d2<=9;d2++){
                for(int d3=0;d3<=9;d3++){
                    for(int d4 = 0;d4<=9;d4++){
                        int num = d1*1e6+d2*1e5+d3*1e4+d4*1e3+d3*1e2+d2*1e1+d1;
                        if(num>b) return;
                        judgeandprint(num);
                    }
                }
            }
        }
    }else if(digit == 8){
        for(int d1 =1;d1<=9;d1+=2){
            for(int d2=0;d2<=9;d2++){
                for(int d3=0;d3<=9;d3++){
                    for(int d4 = 0;d4<=9;d4++){
                        int num = d1*1e7+d2*1e6+d3*1e5+d4*1e4+d4*1e3+d3*1e2+d2*1e1+d1;
                        if(num>b) return;
                        judgeandprint(num);
                    }
                }
            }
        }
    }
}
int getdigit(int n){
    int digit = 0;
    while(n){
        digit++;
        n/=10;
    }
    return digit;
}
int main(){
    scanf("%d %d",&a,&b);
    for(int i=getdigit(a);i<=min(getdigit(b),8);i++){
        printnum(i);
    }
}