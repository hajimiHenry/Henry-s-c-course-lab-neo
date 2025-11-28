#include <stdio.h>
int prime(int x);
int main( )                                  
{ int d;  
 scanf("%d",&d);      
 if(prime(d)==1)
     printf("%d is a prime number",d);             
 else 
     printf("%d is not a prime number",d);   
  return 0;
}

int prime(int x){
    if (x<2)
    {
    return 0;
    }
    if (x==2)
    {
       return 1; /* code */
    }
    if (x%2==0)
    {
      return 0;  /* code */
    }
    for (int i = 3; i < x; i++)
    {
        if (x%i==0)
        {
          return 0;  /* code */
        }
    }
return 1;
}