// 方法一：fgets 读整行 + <ctype.h>
// 说明：isalpha(c) 判断 c 是否为英文字母（A-Z 或 a-z）；
//      isdigit(c) 判断 c 是否为数字字符（0-9）。
// 注意：传给 ctype 系列函数的参数应先转换为 unsigned char，避免带符号拓展导致未定义行为。
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char buf[1005];
    if (!fgets(buf, sizeof(buf), stdin)) {
        printf("0 0 0 0");
        return 0;
    }

    int letters = 0, digits = 0, spaces = 0, others = 0;
    for (int i = 0; buf[i] != '\0' && buf[i] != '\n'; ++i) {
        unsigned char c = (unsigned char)buf[i];
        if (isalpha(c)) ++letters;
        else if (isdigit(c)) ++digits;
        else if (c == ' ') ++spaces;
        else ++others;
    }

    printf("%d %d %d %d", letters, digits, spaces, others);
    return 0;
}

