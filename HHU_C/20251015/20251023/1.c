// 编写程序实现 “快递运费计算” 功能：
// 1)	快递公司规定：首重 1kg 内（含 1kg），江浙沪地区运费 8 元，其他地区 12 元；
// 2)	超过 1kg 的部分，江浙沪地区每增加 0.5kg 加收 2 元（不足 0.5kg 按 0.5kg 算），其他地区每增加 0.5kg 加收 3 元（不足 0.5kg 按 0.5kg 算）；
// 3)	用户需输入快递重量（浮点型，单位 kg）和地区代码（‘A’代表江浙沪，‘B’代表其他地区）；
// 程序计算并输出总运费，结果保留 1 位小数。
#include<stdio.h>
#include<math.h>
int main(void){
    double m,money;char position;
    printf("请输入快递重量（浮点型，单位 kg）和地区代码（'A'代表江浙沪，'B'代表其他地区）：\n");
    scanf("%lf %c",&m,&position);
    if(position == 'A'){
        money = 8;
    }else{
        money = 12;
    }
    if(m>1){
        if(position == 'A'){
            money += ceil((m-1)/0.5)*2;
        }else{
            money += ceil((m-1)/0.5)*3;
        }
    }
    printf("快递费用%.1f元\n",money);
    return 0;
}