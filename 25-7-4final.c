#include <stdio.h>
int main(void){
    int i;
    int isprime=1;
    int x;
    scanf("%d",&x);
    if (x<2)
    {
     isprime=0;   /* code */
    }
    else{
        for ( i = 2; i <x; i++)
        {
          if (x%i==0)
          {
           isprime=0;
           break; /* code */
          }
            /* code */
        }
    }
    
    if (isprime==0)
    {
      printf("%d is not a prime.",x) ; /* code */
    }
    else
    {
      printf("%d is a prime.",x);
    }
    return 0;
}
