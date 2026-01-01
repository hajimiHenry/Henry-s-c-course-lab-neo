    #include <stdio.h>


        typedef struct {
            char name[21];
            char gender;   
            int annual;
        } Emp;

        int main(void)
        {
            Emp a[10];
            int total=0;
            int malecount=0,femcount=0;
            int worstmale=-1,worstfem=-1;

            for (int i = 0; i < 10; i++)
            {
                int q1,q2,q3,q4;
                scanf("%20s %c %d %d %d %d",a[i].name,&a[i].gender
                    ,&q1,&q2,&q3,&q4);
                
                a[i].annual=q1+q2+q3+q4;

                total+=a[i].annual;

                if (a[i].gender=='m')
                {
                    malecount+=1;
                    if (worstmale==-1||a[i].annual<=a[worstmale].annual)
                    {
                        worstmale=i;
                        /* code */
                    }
                    /* code */
                }
                else if (a[i].gender=='f')
                {
                    femcount+=1;
                    if (worstfem==-1||a[i].annual<=a[worstfem].annual)
                    {
                        worstfem=i;
                        /* code */
                    }
                    /* code */
                }
            }

            int aver=total/(femcount+malecount);

            if (malecount>1)
            {
                printf("male: %s %d\n",a[worstmale].name,a[worstmale].annual);
                /* code */
            }
            if (femcount>1)
            {
                printf("female: %s %d\n",a[worstfem].name,a[worstfem].annual);
                /* code */
            }

            printf("the annual aver is %d\n",aver);

            for (int j = 0; j < 10; j++)
            {
                if ((a[j].gender=='m')&&a[j].annual>aver)
                {
                    printf("%s %d\n",a[j].name,a[j].annual);
                    /* code */
                }
            }
        for (int k = 0; k < 10; k++)
        {
            if ((a[k].gender=='f')&&a[k].annual>aver)
            {
                printf("%s %d\n",a[k].name,a[k].annual);
            }
        }
        /*for (int m = 0; m < malecount; m++)
            {
                if (a[m].annual>aver)
                {
                    printf("%s%d",a[j].name,a[j].annual);
                }
            }*/ 
            return 0;
        }
        /*int main(void)
        {
            char name[10][50];
            char gender;
            int q1,q2,q3,q4;
            int total[10];
            int anual=0;
            int malecount=0,femcount=0;

            for (int i = 0; i < 10; i++)
            {
                scanf("%s",name);
                scanf(" %c",&gender);
                scanf("%d%d%d%d",&q1,&q2,&q3,&q4);
                int sum=q1+q2+q3+q4;
                total[i]=sum;
                anual+=total[i];
                if (gender=='f')
                {
                    femcount+=1;
                
                }
                if (gender=='m')
                {
                    malecount+=1;
                }
            }
        }*/