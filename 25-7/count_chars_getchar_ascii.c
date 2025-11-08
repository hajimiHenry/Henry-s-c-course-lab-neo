// 方法四：逐字符 getchar() + 纯 ASCII 判断
#include <stdio.h>

static int is_letter_ascii(unsigned char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(void) {
    int letters = 0, digits = 0, spaces = 0, others = 0;
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        unsigned char c = (unsigned char)ch;
        if (is_letter_ascii(c)) ++letters;
        else if (c >= '0' && c <= '9') ++digits;
        else if (c == ' ') ++spaces;
        else ++others;
    }

    printf("%d %d %d %d", letters, digits, spaces, others);
    return 0;
}

