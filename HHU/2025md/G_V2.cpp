#include<iostream>
using namespace std;
const int N =1e5+10;
int n,k,a[N],b[N];
using ll= long long;
//核心思想：二分+贪心
bool check(ll bmax){//判断当前最大疲劳值能否在k天内完成
    ll days = 1,b_current = 0;
    for(ll i=1;i<=n;i++){
        if(b_current +b[i]<=bmax){//没有超过最大疲劳值，加！
            b_current+=b[i];
        }else{
            days++;//需要再开一天来完成任务
            b_current = b[i];//注意！不是0，应该将这天的任务放进去
        }
    }
    return days<=k;
}
int main(){
    scanf("%d%d",&n,&k);
    ll left = 0; //二分左边界，单疲劳度最大值（最好的情况）
    ll right = 0;//二分右边界，所有疲劳度和（最差的情况）
    
    for(ll i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i]*a[i];
        if(b[i]>left){
            left = b[i];
        }
        right +=b[i];
    }
    // 二分
    ll ans = right;
    while(left<=right){
        ll mid = left + (right-left)/2;
        if(check(mid)){//判断一下中间值行不行，如果行说明压榨不够彻底
            ans = mid;
            right = mid-1;
        }else{//压榨太多了
            left = mid +1;
        }
    }
    printf("%lld",ans);
}   