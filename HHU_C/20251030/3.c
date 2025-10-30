#include<stdio.h>
double funcs(int x,int y){ //计算函数s值的函数
    return (x + 2*y)*1.0/(3*x-y);//返回对应值，*1.0完成类型转换
}
int main(void){
    double smax=funcs(2,2);int x_pos=2, y_pos=2;//定义s_max初始值为x,y均取2时的取值，且此时是一个有效的起点
    for(int x=2;x<=9;x++){ //通过两层循环遍历x,y取遍2到9
        for(int y=2;y<=9;y++){
            if(3*x-y == 0) continue;//如果被除数为0，跳出本次的循环
            double s = funcs(x,y); //计算当前x,y下的s的值
            if(s > smax){ //找到更大值
                smax = s; //更新最大值记录
                x_pos = x; //将最大值的x,y坐标都记录下来
                y_pos = y;
            }
        }
    }
    printf("s取最大值时x=%d,y=%d,此时s=%f\n",x_pos,y_pos,smax);//输出
    return 0;
}