#include <stdio.h>

int main(void) {
    int n, digit1, digit2, digit3;

    printf("请输入一个三位整数: ");

    if (scanf("%d", &n) != 1) {
        printf("输入错误！\n");
        return 1;
    }

    if (n < 100 || n > 999) {
        printf("错误：请输入100-999之间的整数！\n");
        return 1;
    }

    digit1 = n / 100;          // 百位
    digit2 = n / 10 % 10;      // 十位
    digit3 = n % 10;           // 个位

    int sum = digit1 + digit2 + digit3;
    int product = digit1 * digit2 * digit3;

    printf("各位数字之和: %d\n", sum);
    printf("各位数字之积: %d\n", product);

    return 0;
}
