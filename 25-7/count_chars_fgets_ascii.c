// 方法二：fgets 读整行 + 纯 ASCII 判断（不依赖 <ctype.h>）
#include <stdio.h>

static int is_letter_ascii(unsigned char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(void) {
    char buf[1005];
    if (!fgets(buf, sizeof(buf), stdin)) {
        printf("0 0 0 0");
        return 0;
    }

    int letters = 0, digits = 0, spaces = 0, others = 0;
    for (int i = 0; buf[i] != '\0' && buf[i] != '\n'; ++i) {
        unsigned char c = (unsigned char)buf[i];
        if (is_letter_ascii(c)) ++letters;
        else if (c >= '0' && c <= '9') ++digits;
        else if (c == ' ') ++spaces;
        else ++others;
    }

    printf("%d %d %d %d", letters, digits, spaces, others);
    return 0;
}

