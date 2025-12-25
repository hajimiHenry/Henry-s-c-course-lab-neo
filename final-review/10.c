    #include<stdio.h>
    int main(void)
    {
        int N;
        scanf("%d",&N);
        double arr[300];

        for (int i = 0; i < N; i++)
        {
            scanf("%lf",&arr[i]);
            /* code */
        }
        
        double sum=0;

        for (int j = 0; j < N; j++)
        {
        sum+=arr[j]; /* code */
        }
        double aver=sum/N;

        int index=0;
        for (int k = 0;k < N; k++)
        {
            if (arr[k]>aver)
            {
                index+=1;
                /* code */
            }
            /* code */
        }
        
        printf("%d",index);
        

        return 0;
    }