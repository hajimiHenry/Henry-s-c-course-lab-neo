#include<stdio.h>
int main(void){

    int arr[10][10]={0};
    int n;
    scanf("%d",&n);
    //1.读入了n

    //外层循环控制行，内层控制列
    for (int i = 0; i < n; i++)
    {
        //开始行内运算之前，先把行首和尾摆出来
        arr[i][0]=1;
        arr[i][i]=1;
        for (int j = 1; j < i; j++)//这里限定了参与内层循环的中间值的范围
        {//算出中间值
            arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            printf("%4d",arr[i][j]);
        }
        printf("\n");
    }
return 0;

}