#include <stdio.h>
#include <ctype.h>

int main(void) {
    char x;
    if (scanf(" %c", &x) != 1) {
        return 0;
    }

    x = (char)toupper((unsigned char)x);

    switch (x) {
    case 'A':
        printf("90");
        break;
    case 'B':
        printf("80");
        break;
    case 'C':
        printf("70");
        break;
    case 'D':
        printf("60");
        break;
    case 'E':
        printf("59");
        break;
    default:
        printf("Data Error!");
        break;
    }

    return 0;
}

