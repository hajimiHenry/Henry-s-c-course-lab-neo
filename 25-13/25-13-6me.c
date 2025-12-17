#include<stdio.h>

void swap(int *a, int *b);
void task(int (*array)[5]);
int isfixed(int *p,int *f[],int count);

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

    int *fixed[5];
    fixed[0]=&array[2][2];
    

    for (int g = 0; g < 4; g++)
    {
        /* code */
        int *pmin=NULL;

        int a[4]={0,0,4,4};
        int b[4]={0,4,0,4};

        int *target = &array[a[g]][b[g]];

        for (int l = 0; l < 5; l++)
        {
            for (int h = 0; h < 5; h++)
            {
                int *cur=&array[l][h];
               if (isfixed(cur,fixed,g+1))
               {
                continue;
               }
               if (pmin == NULL||*pmin>*cur)
               {
                 pmin=cur;
               }                                                    
            }
            
        }
        swap(pmin, target);
        fixed[1+g]=&array[a[g]][b[g]];
    }
    
}

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int isfixed(int *p,int *f[],int count)
{
    for (int i = 0; i < count; i++)
    {
        if (p==f[i])
        {
            return 1;/* code */
        }
    }
    return 0;
}
