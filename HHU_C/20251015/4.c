#include<stdio.h>
#include<math.h>

int main(void){
    double m1,m2,v1,v2,percent,lost_energy,total_energy;//定义变量
    printf("请分别输入m1 m2和v1 v2,中间用空格隔开\n");//提示
    scanf("%lf %lf %lf %lf",&m1,&m2,&v1,&v2);//输入
    total_energy = 0.5*m1*pow(v1,2)+0.5*m2*pow(v2,2);//总动能
    lost_energy = 0.5 * (m1*m2)/(m1+m2) * pow(v1-v2,2);//损失的动能
    percent = lost_energy / total_energy * 100;//百分比
    printf("损失的动能(单位:焦耳):%.2f\n损失的动能占总动能的百分比:%.2f%%",lost_energy,percent);//输出
    return 0;
}