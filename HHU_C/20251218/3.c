#include<stdio.h>
int ishuiwennum(int n){ //自定义函数，判断是否为回文数
    int tmp = n,n2 = 0; //定义临时变量tmp为n,n2（反过来的数）初始为0
    while(tmp){ //在tmp＞0的时候一直执行
        n2 = n2*10 + tmp % 10; //取出tmp的最后一位，加在n2后面
        tmp/=10; //tmp去除最后一位
    }
    return n==n2; //返回n是否和n2相等
}
int isprime(int n){ //自定义函数，判断是否为素数
    if(n == 1) return 0; //特判，1不是素数，返回0
    int i = 2; //临时变量i设为2
    while(i*i <= n){ //只需要遍历到sqrt(n)即可，为节省开销使用i*i<=n
        if(i<n && n%i==0) return 0; //如果i不是n本身且i能被n除尽那么它一定不是素数，直接返回0
        i++;//i自增
    }
    return 1;//否则返回1
}
int main(void){
    int m,k;//定义变量m,k
    scanf("%d %d",&m,&k);//输入m,k
    if(m%2==0) m++; //注意到，孪生素数必然是奇数，所以如果m是偶数，那么让它加上1变成奇数
    while(k){ //k>0的时候一直执行，这里k代表剩余需要查找的数的个数
        if(ishuiwennum(m) && isprime(m) && isprime(m+2)){ //判定孪生素数条件(m是回文数,m和m+2是素数，考虑到&&的短路性，将最容易判断的放在前面提升运行效率
            printf("(%d,%d)\n",m,m+2); //是孪生素数
            k--; //将k自减
        }
        m+=2; //考虑到孪生素数必然为奇数，这里直接自增2
    }  
    return 0; //结束程序
}