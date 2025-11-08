#include <stdio.h>

int main(void) {
    int letters = 0; 
    int digits  = 0; 
    int spaces  = 0;  
    int others  = 0;   

    int ch;
    while ((ch = getchar()) != EOF && ch != '\n' && ch != '\r') {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            letters++;
        } else if (ch >= '0' && ch <= '9') {
            digits++;
        } else if (ch == ' ') {
            spaces++;
        } else {
            others++;
        }
    }

    printf("%d %d %d %d\n", letters, digits, spaces, others);
    return 0;
}
