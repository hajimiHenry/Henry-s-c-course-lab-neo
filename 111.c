// 统计一行输入中不同类型字符的数量：字母、数字、空格与其他字符。
#include <ctype.h>
#include <stdio.h>

int main(void) {
    int ch;
    int letter_count = 0;
    int digit_count = 0;
    int space_count = 0;
    int other_count = 0;

    // 逐字符读取直到换行或文件结束，对每种字符分类计数。
    while (ch != '\n') {
        if (isalpha(ch)) {
            ++letter_count;
        } else if (isdigit(ch)) {
            ++digit_count;
        } else if (ch == ' ') {
            ++space_count;
        } else {
            ++other_count;
        }
    }

    printf("%d %d %d %d", letter_count, digit_count, space_count, other_count);
    return 0;
}
