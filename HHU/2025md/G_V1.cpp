//15 WA
#include<iostream>
using namespace std;
const int N =1e5+10;
int n,k,a[N];
int main(){
    int cnt = 0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt +=a[i];
    }
    double aboutans = cnt*1.0 / k;//大致每天需要的单词书
    int dqdcs;//当前组合内单词数量
    int maxb = 0,b=0;
    for(int i=1;i<=n;i++){
        dqdcs+=a[i];//加入第i天的
        b+=a[i]*a[i];
        if(dqdcs>aboutans||(dqdcs<aboutans && dqdcs+a[i+1]>aboutans && aboutans < (dqdcs+dqdcs+a[i+1])/2)){
            if(b>maxb){maxb=b;}
            b = 0;
            dqdcs = 0;
        }
    }
    printf("%d",maxb);
    return 0;
}