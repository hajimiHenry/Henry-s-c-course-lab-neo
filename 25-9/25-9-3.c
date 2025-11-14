#include<stdio.h>
int main(void){
    int arr[8];
    for (int i = 0; i < 8; i++)
    {
    scanf("%d",&arr[i]);
    }
    //到此先把数组里的东西输入了
    //题干显然是在要求我用冒泡循环，似乎只用走一趟
    int temp;
    for (int i = 0; i < 7; i++)
    {
        if (arr[i]>arr[i+1])
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    
    for ( int k= 0; k <8; k++)
    {
        printf("%3d",arr[k]);
    }

return 0;

}