#include<iostream>
using namespace std;
using ll = long long;
int main(){
    ll T,n;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        ll processed = 0;  // 已处理的数字个数
        ll level = 1;       // 当前层数
        ll cnt = 0;         // 总查找次数
        
        while(processed < n){
            ll capacity = 1LL << (level - 1);  // 这一层的容量
            ll actual = min(capacity, n - processed);  // 实际放多少个
            cnt += level * actual;
            processed += actual;
            level++;
        }
        printf("%lld\n",cnt);
    }
}
