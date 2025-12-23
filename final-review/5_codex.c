#include <stdio.h>

static int is_prime(int x)
{
    if (x < 2)
        return 0;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    char phones[10][12];
    for (int i = 0; i < n; i++)
        scanf("%11s", phones[i]);

    char c;
    int N, M;
    scanf(" %c%d%d", &c, &N, &M);

    for (int p = 0; p < n; p++)
    {
        char s[12];
        for (int i = 0; i < 12; i++)
            s[i] = phones[p][i];

        for (int i = N; i <= M; i++)
            s[i] = c;

        if (!(N <= 10 && 10 <= M))
        {
            int sum = 0;
            for (int i = 0; i < 11; i++)
            {
                if (s[i] >= '0' && s[i] <= '9')
                    sum += s[i] - '0';
            }

            int last_digit = s[10] - '0';
            int new_last_digit = is_prime(sum) ? (last_digit + sum) % 10 : sum % 10;
            s[10] = (char)('0' + new_last_digit);
        }

        puts(s);
    }

    return 0;
}
