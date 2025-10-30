#include<iostream>
#include<cmath>
using namespace std;

long long ans(long long m,long long n,long long money){
    long long count = 0;

    long long left=m,right=min(money,n);
    if(left > right){
        return 0;
    }
    while(left % 5!=0){
        left++;
    }
    while(right % 5 !=0){
        right--;
    }
    // printf("%lld %lld ; %lld %lld\n",m,n,left,right);
    count = (right - left)/5 + 1;
    return count;
}
int main(){
    long long A,B,x,y;
    while(cin>>A>>B){
        //审题：总费用的5%-10%,感谢gemini提醒
        // x = A + (long long)(ceil(double(A)*0.05));
        // y = A + (long long)(A*0.1);
        // T<=10/9 A T>=20/19 A
        // 转换为整数计算使结果更精确
        // ceil(20*A/19) = (20*A + 19 - 1) / 19
        x = (20LL*A+18)/19;
        y = (10LL*A)/9;

        printf("%lld\n",ans(x,y,B));
    }
}