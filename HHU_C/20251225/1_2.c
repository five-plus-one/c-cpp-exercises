#include <stdio.h>
#include <string.h>
#include <ctype.h>  // 用于 tolower() 函数
int main() {
    char ch1[1300], ch2[1300];
    // 读取输入
    fgets(ch1, sizeof(ch1), stdin);
    fgets(ch2, sizeof(ch2), stdin);
    int i = 0, j = 0;
    int flag = 1;
    // 处理两个字符串
    while (1) {
        // 跳过 ch1 中的空格
        while (ch1[i] != '\0' && ch1[i] == ' ') {
            i++;
        }
        // 跳过 ch2 中的空格
        while (ch2[j] != '\0' && ch2[j] == ' ') {
            j++;
        }
        // 检查是否都到达字符串末尾
        if (ch1[i] == '\0' || ch1[i] == '\n') {
            if (ch2[j] == '\0' || ch2[j] == '\n') {
                break;  // 都结束，相等
            } else {
                flag = 0;  // ch1结束但ch2还有字符
                break;
            }
        }
        if (ch2[j] == '\0' || ch2[j] == '\n') {
            flag = 0;  // ch2结束但ch1还有字符
            break;
        }  
        // 转换为小写后比较
        if (tolower(ch1[i]) != tolower(ch2[j])) {
            flag = 0;
            break;
        }
        i++;
        j++;
    }
    if (flag) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
