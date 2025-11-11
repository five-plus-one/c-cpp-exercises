#include <iostream>
#include <cmath> 
using namespace std;

const int N = 1e4;
struct score {
    int W = 0; 
    int L = 0;
};

score l11[N], l21[N];
int l11_n = 1, l21_n = 1;

void process(char ch) {
    // 1. 先更新当前局的比分
    if (ch == 'W') {
        l11[l11_n].W++;
        l21[l21_n].W++;
    } else if (ch == 'L') {
        l11[l11_n].L++;
        l21[l21_n].L++;
    }

    // 2. 检查11分制这一局是否结束
    int w11 = l11[l11_n].W;
    int l11_score = l11[l11_n].L;
    // 统一的、简洁的结束条件
    if ((w11 >= 11 && w11 - l11_score >= 2) || (l11_score >= 11 && l11_score - w11 >= 2)) {
        l11_n++; // 切换到下一局
    }

    // 3. 检查21分制这一局是否结束
    int w21 = l21[l21_n].W;
    int l21_score = l21[l21_n].L;
    // 同样统一的、简洁的结束条件
    if ((w21 >= 21 && w21 - l21_score >= 2) || (l21_score >= 21 && l21_score - w21 >= 2)) {
        l21_n++; // 切换到下一局
    }
}

int main() {
    char ch;
    while ((ch = getchar()) != 'E') {
        if (ch == 'W' || ch == 'L') {
            process(ch);
        }
    }

    for (int i = 1; i <= l11_n; i++) {
        printf("%d:%d\n", l11[i].W, l11[i].L);
    }
    printf("\n");
    for (int i = 1; i <= l21_n; i++) {
        printf("%d:%d\n", l21[i].W, l21[i].L);
    }
    return 0; 
}
