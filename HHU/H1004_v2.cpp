//这是gemini写的
#include <iostream>
#include <cmath>

int main() {
    long long S;
    
    while (std::cin >> S) {
        int count = 0;
        // x 的最大值不会超过 sqrt(S)
        long long r = static_cast<long long>(sqrt(S));

        // 1. 检查坐标轴上的点 (r, 0) 和 (0, r)
        if (r * r == S) {
            count += 4;
        }

        // 2. 检查象限内的点 (x > 0, y > 0, x != y)
        // 循环到 x*x < S/2，可以保证 x < y，避免重复和 x=y 的情况
        for (long long x = 1; x * x * 2 < S; ++x) {
            long long y_squared = S - x * x;
            long long y = static_cast<long long>(sqrt(y_squared));

            if (y * y == y_squared) {
                // 找到一组(x, y) 且 x!=y，可以生成8个点
                // (±x, ±y) 和 (±y, ±x)
                count += 8;
            }
        }
        
        // 3. 单独检查 x = y 的情况
        // 如果 S = 2*x*x，我们就有(±x, ±x)这4个点
        if (S % 2 == 0) {
            long long x_squared = S / 2;
            long long x = static_cast<long long>(sqrt(x_squared));
            if (x * x == x_squared) {
                 // 确保这个点不是轴上的点，即x>0
                 if (x > 0) {
                     count += 4;
                 }
            }
        }

        printf("%d\n", count);
    }
    return 0;
}
