#include <stdio.h>

// 判断某一年是否为闰年，是返回 1，不是返回 0
int is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main(void) {
    int year, month, day;
    // 以 年/月/日 的格式读入日期，例如 2024/3/15
    scanf("%d/%d/%d", &year, &month, &day);

    // 每个月的天数表，下标 1~12 对应 1~12 月
    int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 如果是闰年，把 2 月改为 29 天
    if (is_leap(year)) {
        md[2] = 29;
    }

    // 先把这一天加一
    day++;
    // 如果超过本月天数，就进位到下一个月
    if (day > md[month]) {
        day = 1;
        month++;
        // 如果月份超过 12 月，则进位到下一年 1 月
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    // 按 年/月/日 的格式输出下一天的日期
    printf("%d/%d/%d", year, month, day);
    return 0;
}
