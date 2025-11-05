//5plus1
#include<iostream>
// #include<algorithm>
using namespace std;
const int N = 1e7+11;
int T,n,k,num1,num0,tzqueue[N];
char mt[N]; //直接读入整个字符串，从而实现优化
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        num1=num0=0;
        scanf(" %s",mt);
        for(int i=0;i<n;i++){
            if(mt[i]=='1'){
                num1++;
            }else{
                num0++;
            }
        }
        // 检查前num0数里面有几个1(需要被交换到后面)
        int needtz = 0;
        int j=0;
        for(int i=0;i<num0;i++){
            if(mt[i]=='1'){
                needtz++;
                j++;
                tzqueue[j]=i;
            }
        }
        int swaptimes = needtz*2;
        if(swaptimes>k){ //不可能调好的()
            printf("N0\n");
            continue;
        }
        //找到后半部分的0
        int pos = num0-1;
        int zdnum = 0;
        while(zdnum<needtz){
            pos++;
            if(mt[pos]=='0'){
                j++;
                tzqueue[j] = pos;
                zdnum++;
            }
        }
        // sort(tzqueue+1,tzqueue+j+1);
        printf("YE5\n%d ",swaptimes);
        for(int i=1;i<=swaptimes;i++){
            printf("%d ",tzqueue[i]+1);
        }
        printf("\n");
        
    }
}