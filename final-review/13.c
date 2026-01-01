#include<stdio.h>
#include<string.h>

int checkequl(char* arr);

int main(void)
{
    int T;
    scanf("%d",&T);

    int num;
    char arr[50];

    int len=0;
    int max;
    


    for (int i = 0; i < T; i++)
    {
        int found=1;
        int max;
        scanf("%d",&num);
        char maxstr[50]="";
        for (int j = 0; j < num; j++)
        {
            scanf("%s",arr);
            if (!checkequl(arr))
            {
                found=0;
                /* code */
            }
            if (j==0||strcmp(arr,maxstr)>0)
            {
                strcpy(maxstr,arr);
            }
        }
         if (found==1)
            {
                printf("YES ");
                /* code */
            }
            else
            {
                printf("NO ");
            }
            
            printf("%s\n",maxstr);
        /* code */
    }
    
return 0;
}


int checkequl(char* arr)
{
    int len=strlen(arr);
    int first=0;
    int last=len-1;
    for (int p = 0; p < (len/2) ; p++)
    {
        if (arr[first]!=arr[last])
        {
            return 0;
            /* code */
        }
        first++;
        last--;
    }

    return 1;
}