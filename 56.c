#include <stdio.h>

int main(void) {
    char a = 'A';
    char b = '\101';   // 八进制 101 → 65 → 'A'
    char c = '\x41';   // 十六进制 41 → 65 → 'A'
    char d = 65;       // 直接数值 65
    char e = '1';      // 字符 1，码值 49
    int  x = 1;        // 整数 1

    printf("a: %c, %d\n", a, a);
    printf("b: %c, %d\n", b, b);
    printf("c: %c, %d\n", c, c);
    printf("d: %c, %d\n", d, d);
    printf("e: %c, %d\n", e, e);
    printf("x: %d\n", x);

    if (a == b && b == c && c == d) {
        printf("a, b, c, d 的数值完全相同\n");
    }
    if ('1' != 1) {
        printf("字符'1'和整数1的数值不同\n");
    }
    if ('1' - '0' == 1) {
        printf("字符'1'减去字符'0'等于整数1\n");
    }

    return 0;
}
