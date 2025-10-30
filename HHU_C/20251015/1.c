#define _USE_MATH_DEFINES //修复M_PI未定义问题
#include<stdio.h>
#include<math.h>

int main(void){
    double R,L,S,V; //定义变量
    printf("请输入圆的半径 R: "); // 增加用户提示，提高交互性
    scanf("%lf",&R); //输入
    L = 2 * M_PI * R; //周长
    S = M_PI * pow(R,2); //面积
    V = 4.0 * M_PI * pow(R,3) / 3;//体积
    printf("周长：%.2f 面积：%.2f 体积：%.2f",L,S,V);//输出
    return 0;
}

