#include<stdio.h>
#include<string.h>
void input(char name[10][20],int num[]);
void sort(char name[10][20],int num[]);
int search(int num[],int one);

int main()
{   int i,one,k;
    char name[10][20];
    int num[10];
    input(name,num);
    sort(name,num);
    for(i=0;i<10; i++)
        printf("%s %d\n",name[i],num[i]);
    scanf("%d",&one);
    k=search(num,one);
    if(k!=-1) puts(name[k]);
        else puts("NO");
    return 0;
}

/* 你的程序将嵌在这里 */
void input(char name[10][20],int num[])
{
    for (int i = 0; i < 10; i++)
    {
        scanf("%19s %d",name[i],&num[i]);
    }
}

void sort(char name[10][20],int num[])
{
    for (int i = 0; i <9 ; i++)
    {
        for (int j = 0; j <9-i; j++)
        {
            if (num[j]>num[j+1])
            {
                int tamp=num[j+1];
                num[j+1]=num[j];
                num[j]=tamp;
                char temp[20];
                strcpy(temp,name[j+1]);
                strcpy(name[j+1],name[j]);
                strcpy(name[j],temp);
            }

        }
        
    }
    
}

int search(int num[],int one)
{

    int low=0;
    int high=9;
    while (low<=high)
    {
       int mid=(low+high)/2;
       if (num[mid]<one)
       {
        low=mid+1;
       }
       else if (num[mid]>one)
       {
        high=mid-1;
       }
       else if (num[mid]==one)
       {
        return mid;
       }
    }
    return -1;
}
