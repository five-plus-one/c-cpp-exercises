#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// --- 高精度模板开始 ---
struct BigInt {
    vector<int> digits; // 存储每一位，下标0是低位

    // 1. 构造函数：支持初始化为 0 或某个整数
    BigInt(long long n = 0) {
        if (n == 0) digits.push_back(0);
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
    }

    // 2. 乘法：高精度 * 低精度 (BigInt * int)
    // 比如：123456789 * 5
    BigInt operator*(int x) const {
        BigInt res;
        res.digits.clear();
        long long carry = 0; // 进位
        for (int i = 0; i < digits.size() || carry; i++) {
            long long current = carry + (i < digits.size() ? (long long)digits[i] * x : 0);
            res.digits.push_back(current % 10);
            carry = current / 10;
        }
        // 去除前导0（虽然乘法一般不会产生前导0，除非乘以0）
        while (res.digits.size() > 1 && res.digits.back() == 0) res.digits.pop_back();
        return res;
    }

    // 3. 除法：高精度 / 低精度 (BigInt / int)
    // 比如：123456789 / 5
    BigInt operator/(int x) const {
        BigInt res;
        res.digits.clear(); // 结果暂存
        // 除法必须从高位算起，但我们存的是低位在前，所以要倒着遍历
        long long remainder = 0;
        bool hasStarted = false; // 用于标记是否开始存入非0数（处理前导0）
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            remainder = remainder * 10 + digits[i];
            int sh = remainder / x; // 商
            remainder %= x;         // 余数

            if (sh != 0 || hasStarted) {
                res.digits.push_back(sh);
                hasStarted = true;
            }
        }
        
        // 如果结果是0（hasStarted从未变true）
        if (!hasStarted) res.digits.push_back(0);
        
        // 上面存的时候是从高位存的，也就是现在的 vector 是 [高位, ..., 低位]
        // 但我们的 BigInt 规范是 [低位, ..., 高位]，所以要反转
        reverse(res.digits.begin(), res.digits.end());
        return res;
    }

    // 4. 比较：小于号 (BigInt < BigInt)
    bool operator<(const BigInt& other) const {
        if (digits.size() != other.digits.size()) 
            return digits.size() < other.digits.size();
        // 长度相同，从高位开始比
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != other.digits[i])
                return digits[i] < other.digits[i];
        }
        return false; // 相等或大于
    }
    
    // 5. 输出流重载 (cout << BigInt)
    friend ostream& operator<<(ostream& os, const BigInt& bi) {
        if (bi.digits.empty()) {
            os << 0;
            return os;
        }
        // 倒序打印
        for (int i = bi.digits.size() - 1; i >= 0; i--) {
            os << bi.digits[i];
        }
        return os;
    }
};
// --- 高精度模板结束 ---
