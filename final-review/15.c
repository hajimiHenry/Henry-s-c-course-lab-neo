#include<stdio.h>
int main(void)
{
    int priceA,priceB,man,wom,numA,numB;
    scanf("%d%d%d%d%d%d",&priceA,&priceB,&man,&wom,&numA,&numB);  

    int total;

    if (wom==0||man==0) 
    {
        total=priceA*numA+priceB*numB;    
        /* code */
    }
    else if (wom!=0&&man!=0)
    {
        if ((priceA*numA)>=(priceB*numB))
        {
            total=priceA*numA;
            /* code */
        }
        else if ((priceA*numA)<(priceB*numB))
        {
            total=priceB*numB;
            /* code */
        }
        
        /* code */
    }
    
    printf("%d",total);
    
}