#include <stdio.h>
int main(void)
{
    int arr[200];
    int index = 0;
    do
    {
        scanf("%d", &arr[index]);
        index += 1;
        /* code */
    } while (arr[index - 1] != -1);

    int check[101] = {0};
    int checkcount = 0;

    for (int i = 0; i < index - 1; i++)
    {
        int found = 0;
        for (int j = 0; j < checkcount; j++)
        {
            if (check[j] == arr[i])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            check[checkcount] = arr[i];
            checkcount++;
            /* code */
        }
    }

    for (int k = 0; k < checkcount; k++)
    {

        printf("%4d", check[k]);
        if ((k + 1) % 10 == 0)
        {
            printf("\n");
            /* code */
        }
    }
    if (checkcount % 10 != 0)
        printf("\n");
}