// 方法三：scanf("%[^\n]") 读到换行前 + <ctype.h>
// 说明：当输入为空行时，scanf 不匹配，直接输出 0 0 0 0。
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char buf[1005] = {0};
    int ok = scanf("%[^\n]", buf); // 读到换行前，不消耗换行
    if (ok != 1) { // 空行或读取失败
        printf("0 0 0 0");
        return 0;
    }

    int letters = 0, digits = 0, spaces = 0, others = 0;
    for (int i = 0; buf[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)buf[i];
        if (isalpha(c)) ++letters;
        else if (isdigit(c)) ++digits;
        else if (c == ' ') ++spaces;
        else ++others;
    }

    printf("%d %d %d %d", letters, digits, spaces, others);
    return 0;
}

