// 最简版本：使用 scanf 的扫描集读取到换行前的整行
// 题意：统计一行中的 字母 数字 空格 其他 字符个数
// 说明：此写法不考虑越界与空行等边角问题（按你的要求简化）
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char buf[1005];                 // 简单的行缓冲区
    int letters = 0, digits = 0, spaces = 0, others = 0;

    // 用扫描集"%[^\n]"读取到换行前的所有字符（包含空格）
    // 若输入为空行，匹配会失败，这里直接输出 0 0 0 0
    if (scanf("%[^\n]", buf) != 1) {
        printf("0 0 0 0");
        return 0;
    }

    // 遍历缓冲区直到字符串结束符'\0'
    for (int i = 0; buf[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)buf[i];
        if (isalpha(c)) ++letters;         // 英文字母 A-Z 或 a-z
        else if (isdigit(c)) ++digits;     // 数字 0-9
        else if (c == ' ') ++spaces;       // 空格，仅统计普通空格
        else ++others;                     // 其它字符
    }

    printf("%d %d %d %d", letters, digits, spaces, others);
    return 0;
}

