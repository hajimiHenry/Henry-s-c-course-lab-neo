#include <stdio.h>
#include <string.h>

int checkequl(const char *arr);

int main(void)
{
    int T;
    if (scanf("%d", &T) != 1) return 0;

    for (int i = 0; i < T; i++)
    {
        int num;
        char arr[50];
        char maxstr[50] = "";
        int all = 1;

        scanf("%d", &num);
        for (int j = 0; j < num; j++)
        {
            scanf("%49s", arr);

            if (!checkequl(arr)) all = 0;

            if (j == 0 || strcmp(arr, maxstr) > 0)
            {
                strcpy(maxstr, arr);
            }
        }

        printf("%s %s\n", all ? "YES" : "NO", maxstr);
    }

    return 0;
}

int checkequl(const char *arr)
{
    int len = (int)strlen(arr);
    int first = 0;
    int last = len - 1;

    while (first < last)
    {
        if (arr[first] != arr[last]) return 0;
        first++;
        last--;
    }

    return 1;
}

