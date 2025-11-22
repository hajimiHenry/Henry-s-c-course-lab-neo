#include <stdio.h>
int main(void){
int n;
scanf ("%d",&n);
int arr[10];
for (int i = 0; i < n; i++)
{
    scanf("%d",&arr[i]);
}

int x;
scanf("%d",&x);

int k=n-1;

while (k>=0 && arr[k]>x)
{
    arr[k+1]=arr[k];
    k--;
}

arr[k+1]=x;

n=n+1;

for (int i = 0; i < n; i++)
{
    printf("%d",arr[i]);
    putchar(' ');
}
putchar('\n');

return 0;
}