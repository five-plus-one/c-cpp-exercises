#include<stdio.h>
#include<math.h>

int main(){
    double init_money,rate_in,year,rate_ex,value_nominal,value_actual,value_rate;//定义变量
    printf("请依次输入初始投资金额、年化收益率（百分比）、投资年限和年均通货膨胀率（百分比），用空格隔开\n");//提示
    scanf("%lf %lf %lf %lf",&init_money,&rate_in,&year,&rate_ex);
    rate_in/=100;rate_ex/=100; //因为输入的是百分比，除以100得到数值
    value_nominal = init_money * pow(1+rate_in,year);//名义终值
    value_actual = value_nominal / pow(1+rate_ex,year);//实际购买力
    value_rate = pow(value_actual / init_money, 1.0 / year) - 1;//实际年华收益率
    printf("名义终值:%.2f\n实际购买力:%.2f\n实际年化收益率:%.2f\n",value_nominal,value_actual,value_rate);//输出
    return 0;

}