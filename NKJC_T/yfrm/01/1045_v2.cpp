//v2
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
int main() {
    double H, S1, V, L, K;
    int n;
    cin >> H >> S1 >> V >> L >> K >> n;
    double g = 10.0;
    double t2 = sqrt(2 * H / g);
    double t1 = sqrt(2 * max(H - K, 0.0) / g); // 处理H-K<0的情况
 
    double left = S1 - V * t2;
    double right = S1 - V * t1 + L;
 
    int count = 0;
    for (int x = 0; x < n; x++) {
        // 使用容错值判断x是否在区间内
        if (x >= left - 1e-5 && x <= right + 1e-5) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}