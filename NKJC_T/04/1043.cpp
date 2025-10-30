#include<iostream>
#include<cstdio>
using namespace std;

string str;
int n, i;
int jg_sgn, jg_type, jg_num, fcstatus;
char x;

void nextjg() {
    jg_sgn = 1;
    
    // 检查是否遇到等号
    if (i < n && str[i] == '=') {
        fcstatus = -1;
        i++;
        jg_type = -3; // 特殊标记，表示这次只是处理了等号
        return;
    }
    
    // 处理符号
    if (i < n && (str[i] == '-' || str[i] == '+')) {
        if (str[i] == '-') {
            jg_sgn = -1;
        }
        i++;
    }
    
    // 处理数字部分
    jg_num = 0;
    bool has_number = false;
    // Bug修复：必须检查 i < n
    while (i < n && str[i] >= '0' && str[i] <= '9') {
        has_number = true;
        jg_num = jg_num * 10 + (str[i] - '0');
        i++;
    }
    
    // 判断是常数还是变量
    // Bug修复：必须检查 i < n
    if (i < n && str[i] >= 'a' && str[i] <= 'z') {
        // 是变量
        x = str[i];
        i++;
        jg_type = 1;
        // Bug修复：如果没有数字部分（如 'x', '+x', '-x'），系数默认为1
        if (!has_number) {
            jg_num = 1;
        }
    } else {
        // 是常数
        jg_type = 0;
    }
}

int main() {
    cin >> str;
    n = str.length();
    fcstatus = 1;
    i = 0;
    
    int x_cnt = 0;  // 变量系数
    int n_cnt = 0;  // 常数项
    
    while (i < n) {
        nextjg();
        
        // 如果只是处理了等号，跳过计算
        if (jg_type == -3) {
            continue;
        }
        
        // cout << "-  " << jg_type << "  " << jg_num << "  " 
        //      << jg_sgn << "  " << fcstatus << endl;
        
        // 移项：把所有项移到左边
        // 方程变为：x_cnt * x + n_cnt = 0
        if (jg_type == 0) {  // 常数项
            n_cnt += jg_num * jg_sgn * fcstatus;
        }
        if (jg_type == 1) {  // 变量项
            x_cnt += jg_num * jg_sgn * fcstatus;
        }
    }
    
    // cout << n_cnt << " " << x_cnt << endl;
    
    // 求解：x_cnt * x + n_cnt = 0
    // x = -n_cnt / x_cnt
    double ans = -n_cnt * 1.0 / x_cnt;
        // Bug修复：处理-0.000的情况
    // 如果常数项为0，解就是0，将其规范化为正零
    if (n_cnt == 0) {
        ans = 0.0;
    }
    printf("%c=%.3lf\n", x, ans);
    
    return 0;
}
