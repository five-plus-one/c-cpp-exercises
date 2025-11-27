#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ===  struct BigInt 代码 ===
struct BigInt {
    vector<int> digits; 
    BigInt(long long n = 0) {
        if (n == 0) digits.push_back(0);
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
    }
    BigInt operator*(int x) const {
        BigInt res;
        res.digits.clear();
        long long carry = 0; 
        for (int i = 0; i < digits.size() || carry; i++) {
            long long current = carry + (i < digits.size() ? (long long)digits[i] * x : 0);
            res.digits.push_back(current % 10);
            carry = current / 10;
        }
        while (res.digits.size() > 1 && res.digits.back() == 0) res.digits.pop_back();
        return res;
    }
    BigInt operator/(int x) const {
        BigInt res;
        res.digits.clear();
        long long remainder = 0;
        bool hasStarted = false; 
        for (int i = digits.size() - 1; i >= 0; i--) {
            remainder = remainder * 10 + digits[i];
            int sh = remainder / x;
            remainder %= x; 
            if (sh != 0 || hasStarted) {
                res.digits.push_back(sh);
                hasStarted = true;
            }
        }
        if (!hasStarted) res.digits.push_back(0);
        reverse(res.digits.begin(), res.digits.end());
        return res;
    }
    bool operator<(const BigInt& other) const {
        if (digits.size() != other.digits.size()) 
            return digits.size() < other.digits.size();
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != other.digits[i])
                return digits[i] < other.digits[i];
        }
        return false; 
    }
    friend ostream& operator<<(ostream& os, const BigInt& bi) {
        if (bi.digits.empty()) {
            os << 0; return os;
        }
        for (int i = bi.digits.size() - 1; i >= 0; i--) {
            os << bi.digits[i];
        }
        return os;
    }
};
// ==========================================

const int N = 1005;

struct Person {
    int left;
    int right;
} p[N];

// 比较函数：按 left * right 从小到大排
// 因为单人的数字较小，相乘不会超过 long long，所以这里不需要用高精度
bool comp(const Person& a, const Person& b) {
    return (long long)a.left * a.right < (long long)b.left * b.right;
}

int main() {
    // 优化 I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    // 读入国王 (存在下标 0)
    cin >> p[0].left >> p[0].right;
    
    // 读入大臣
    for(int i = 1; i <= n; i++){
        cin >> p[i].left >> p[i].right;
    }

    // 排序（只排大臣，从 1 到 n）
    sort(p + 1, p + 1 + n, comp);

    // ans 记录当前找到的最大奖赏，初始化为 0
    BigInt ans(0);
    // cj (乘积) 记录前面所有人的左手乘积，初始为国王的左手
    BigInt cj(p[0].left);

    for(int i = 1; i <= n; i++){
        // 1. 计算当前大臣获得的金币：累乘积 / 他的右手
        BigInt reward = cj / p[i].right;
        
        // 2. 更新最大值 (相当于 ans = max(ans, reward))
        if (ans < reward) {
            ans = reward;
        }
        
        // 3. 将当前大臣的左手乘入累乘积，供后面的人使用
        cj = cj * p[i].left;
    }

    // 直接输出高精度对象
    cout << ans << endl;

    return 0;
}
