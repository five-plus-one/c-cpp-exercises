// 编写程序实现 “个人所得税计算器”（简化版）：
// 个税起征点为 5000 元，应纳税所得额 = 月收入 - 5000 - 专项附加扣除（用户输入，如房租、房贷等，最多不超过 3000 元，超出则按 3000 元计算）；
// •	税率规则：
// o	应纳税所得额≤0：税率 0%，税额 0 元；
// o	0 < 应纳税所得额≤3000：税率 3%；
// o	3000 < 应纳税所得额≤12000：税率 10%，速算扣除数 210；
// o	12000 < 应纳税所得额≤25000：税率 20%，速算扣除数 1410；
// •	税额计算公式：税额 = 应纳税所得额 × 税率 - 速算扣除数；
// •	用户输入月收入（浮点型）和专项附加扣除（整型），程序先校验专项附加扣除合法性（≤3000），再计算应纳税所得额和税额，所有结果保留 2 位小数，
// 输出格式为 “应纳税所得额：X 元，应纳税额：Y 元”。
#include<stdio.h>

int main(){
    double inmoney, taxtotal, taxin;
    int delmoney;

    printf("请依次输入月收入、专项附加扣除\n");
    scanf("%lf %d", &inmoney, &delmoney);

    // 校验专项附加扣除合法性
    if(delmoney > 3000){
        delmoney = 3000;
    }

    // 计算应纳税所得额
    taxtotal = inmoney - 5000 - delmoney;

    // 根据应纳税所得额计算税额
    if(taxtotal <= 0){
        taxin = 0;
    }
    else if(taxtotal <= 3000){
        taxin = taxtotal * 0.03;
    }
    else if(taxtotal <= 12000){
        taxin = taxtotal * 0.10 - 210;
    }
    else if(taxtotal <= 25000){
        taxin = taxtotal * 0.20 - 1410;
    }
    else{
        taxin = taxtotal * 0.20 - 1410;
    }

    printf("应纳税所得额:%.2lf 元,应纳税额:%.2lf 元\n", taxtotal, taxin);

    return 0;
}