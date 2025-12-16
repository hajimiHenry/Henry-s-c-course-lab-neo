#include<stdio.h>

void swap(int *a, int *b);
void task(int (*array)[5]);

int main(void)
{
    int arr[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    
    task(arr);

    for (int p = 0; p < 5; p++)
    {
       for (int k = 0; k < 5; k++)
       {
        printf("%3d",arr[p][k]);
       }
       printf("\n");
    }
    
    return 0;
}

void task(int (*array)[5])
{
    //要把整个里面最大的数放在arr[2][2]
    //最小的从小到大放在00 04 40 44
    //现在把最大的找出来，然后交换

    int max=array[0][0];
    int indexi=0;
    int indext=0;

    for (int i = 0; i < 5; i++)
    {
        for (int t = 0; t < 5; t++)
        {
           if (array[i][t] > max)
           {
            max = array[i][t];
            indexi=i;
            indext=t;
           }
        }
    }
    
    if (indexi != 2 || indext != 2) {
        swap(&array[indexi][indext], &array[2][2]);
    }

    //现在开始处理放在四个角
    //只需要做四次，每次都找到总体里面最小的值，然后同样的用swap
    //加一个判断如果遇到已经改好的就跳过
    
}

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
