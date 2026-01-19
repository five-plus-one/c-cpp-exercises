#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <map>
using namespace std;

// 解析复杂度字符串，返回指数 w
int parseComplexity(const string& s) {
    if (s == "O(1)") return 0;
    // s 格式为 O(n^w)
    int pos = s.find('^');
    string num = s.substr(pos + 1, s.size() - pos - 2);
    return stoi(num);
}

// 判断 x 和 y 的关系，返回该层复杂度贡献
// 返回 0: O(1), 1: O(n), -1: 不执行
int getCost(const string& x, const string& y) {
    if (x == "n") {
        if (y == "n") return 0;
        else return -1; // n 比数字大，不执行
    } else { // x 是数字
        if (y == "n") return 1;
        else {
            int nx = stoi(x), ny = stoi(y);
            if (nx <= ny) return 0;
            else return -1;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int L;
        string complexStr;
        cin >> L >> complexStr;
        int givenW = parseComplexity(complexStr);
        
        cin.ignore(); // 忽略换行符
        
        stack<pair<char, int>> st; // 栈存储 (变量名, 该层复杂度贡献)
        map<char, bool> varInStack; // 当前栈中变量名是否存在
        int maxW = 0; // 实际计算的最大指数
        int currentW = 0; // 当前嵌套的指数
        bool hasError = false;
        bool inUnExecuted = false; // 是否处于不执行的循环中
        int unExecutedDepth = 0; // 不执行循环的深度
        
        for (int i = 0; i < L; i++) {
            string line;
            getline(cin, line);
            if (hasError) continue; // 已经出错，继续读行但不处理
            
            if (line[0] == 'F') {
                // F i x y
                stringstream ss(line);
                char op, var;
                string x, y;
                ss >> op >> var >> x >> y;
                
                // 检查变量名是否重复
                if (varInStack[var]) {
                    hasError = true;
                    continue;
                }
                
                // 判断该层是否执行
                int cost = getCost(x, y);
                
                // 如果当前已经在不执行的循环中，则此层也不执行
                if (unExecutedDepth > 0) {
                    cost = -1;
                }
                
                // 压栈
                st.push({var, cost});
                varInStack[var] = true;
                
                if (cost == -1) {
                    // 不执行的循环
                    unExecutedDepth++;
                } else {
                    // 执行的循环
                    currentW += cost;
                    maxW = max(maxW, currentW);
                }
                
            } else if (line[0] == 'E') {
                // 结束循环
                if (st.empty()) {
                    hasError = true;
                    continue;
                }
                
                auto top = st.top();
                st.pop();
                varInStack[top.first] = false;
                
                if (top.second == -1) {
                    // 结束一个不执行的循环
                    unExecutedDepth--;
                } else {
                    // 结束一个执行的循环
                    currentW -= top.second;
                }
            }
        }
        
        // 最终判断
        if (hasError || !st.empty()) {
            cout << "ERR" << endl;
        } else {
            if (maxW == givenW) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
