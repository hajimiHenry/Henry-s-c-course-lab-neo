#include<stdio.h>
#include<math.h>

int sum(char *arr);
int prime(int n);


int main(void)
{
    int n;
    scanf("%d",&n);
    char arr[n][13];

    for (int i = 0; i < n; i++)
    {
        scanf("%11s",arr[i]);
    }
    
    char c;
    int N,M;
    scanf(" %c%d%d",&c,&N,&M);

    for (int p = 0; p < n; p++)
    {
        for (int k = N; k <= M; k++)
        {
            arr[p][k]=c;
            /* code */
        }
        if (!(N <= 10 && 10 <= M))
        {
        int s=sum(arr[p]);
        int last=arr[p][10]-'0';
        int newlast;
        if (prime(s))
        {
            newlast=(last+s)%10;
        }
        else
        {
            newlast=s%10;
        }
        arr[p][10]=newlast+'0';        }
        
        
    }
    for (int q = 0; q < n; q++)
    {
        printf("%11s\n",arr[q]);
    }
    
    return 0;
}


int sum(char *arr)
{
    int total=0;
    for (int i = 0; i < 11; i++)
    {
        if (arr[i]>='0'&&arr[i]<='9')
        {
            total+=arr[i]-'0';
            /* code */
        }
        /* code */
    }
    return total;
}

int prime(int n)
{
    if (n<2)
    {
        return 0;
        /* code */
    }
    if (n==2)
    {
       return 1; /* code */
    }
    if (n%2==0)
    {
       return 0; /* code */
    }
    for (int i = 3; i <= sqrt(n) ; i++)
    {
        if (n%i==0)
        {
           return 0; /* code */
        }
        /* code */
    }
    return 1;
}