#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 判断能否放入纸张（考虑横竖两种方向）
bool check(long long size, long long L, long long W) {
    long long width  = 2 * size - 1;
    long long height = (3 * size + 1) / 2;
    
    // 方向1：宽对应L，高对应W
    if (width <= L && height <= W) return true;
    // 方向2：宽对应W，高对应L（旋转90度）
    if (width <= W && height <= L) return true;
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long L, W;
    cin >> L >> W;
    
    // size 为正奇数，最大可能的 size 估算
    // width = 2*size-1 <= max(L,W)  =>  size <= (max(L,W)+1)/2
    // height = (3*size+1)/2 <= max(L,W)  =>  size <= (2*max(L,W)-1)/3
    long long maxVal = max(L, W);
    long long maxSize = maxVal; 
 
    if (!check(1, L, W)) {
        cout << 0 << endl;
        return 0;
    }

    long long lo = 1, hi = (maxSize + 1) / 2;
    long long ans = 1; 
    
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        long long size = 2 * mid - 1; 
        
        if (check(size, L, W)) {
            ans = size;  
            lo = mid + 1; 
        } else {
            hi = mid - 1; 
        }
    }
    
    cout << ans << endl;
    return 0;
}