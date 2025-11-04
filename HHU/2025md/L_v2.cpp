#include<iostream>
#include<unordered_map>
using namespace std;
using ll = long long;
const ll N = 1e6+10;
ll a[N], n, k;

int main(){
    scanf("%lld%lld", &n, &k);
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    
    ll ans = 0;
    ll first_valid = n + 1;  // 记录当前left能找到的最早的有效right
    
    for(ll left = 1; left <= n; left++){
        if(first_valid <= n){
            // 已经找到过，直接计算
            ans += n - first_valid + 1;
            continue;
        }
        
        // 需要寻找first_valid
        unordered_map<ll, int> cnt;
        for(ll right = left; right <= n; right++){
            if(cnt.count(k - a[right]) && cnt[k - a[right]] > 0){
                first_valid = right;
                ans += n - right + 1;
                break;
            }
            cnt[a[right]]++;
        }
    }
    
    printf("%lld\n", ans);
    return 0;
}
