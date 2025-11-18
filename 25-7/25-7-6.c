#include <stdio.h>

int main(void) {
    double sum = 0.0, a;
    int count = 0;

    while (count < 10 && scanf("%lf", &a) == 1) {
        if (a == -1) {
            break;       
        }
        sum += a;
        count++;
    }

    if (count == 0) {
        printf("0.00");
    } else {
        printf("%.2f", sum / (double)count);
    }

    return 0;
}
