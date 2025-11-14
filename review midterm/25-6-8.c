#include <stdio.h>

int is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main(void) {
    int year, month, day;
    scanf("%d/%d/%d", &year, &month, &day);

    int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap(year)) {
        md[2] = 29;
    }

    day++;
    if (day > md[month]) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    printf("%d/%d/%d", year, month, day);
    return 0;
}
