#include <stdio.h>

int main(void) {
    char line[1001];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    int i = 0;
    int current_len = 0;
    int current_start = 0;
    int max_len = 0;
    int max_start = 0;

    while (line[i] != '\0' && line[i] != '\n') {
        if (line[i] != ' ') {
            if (current_len == 0) {
                current_start = i;
            }
            current_len++;
        } else {
            if (current_len > 0 && current_len > max_len) {
                max_len = current_len;
                max_start = current_start;
            }
            current_len = 0;
        }
        i++;
    }

    if (current_len > 0 && current_len > max_len) {
        max_len = current_len;
        max_start = current_start;
    }

    for (i = 0; i < max_len; ++i) {
        putchar(line[max_start + i]);
    }
    putchar('\n');

    return 0;
}

