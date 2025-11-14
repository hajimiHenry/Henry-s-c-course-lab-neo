#include <stdio.h>

int main(void) {
    char s[1001];
    int letters = 0, digits = 0, spaces = 0, others = 0;

    if (fgets(s, sizeof(s), stdin) == NULL) {
        return 0;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '\n') {
            break;
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letters++;
        } else if (c >= '0' && c <= '9') {
            digits++;
        } else if (c == ' ') {
            spaces++;
        } else {
            others++;
        }
    }

    printf("%d %d %d %d\n", letters, digits, spaces, others);

    return 0;
}
