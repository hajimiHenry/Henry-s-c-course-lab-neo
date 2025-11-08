#include<stdio.h>

int main(void){
  int a;
  scanf("%d",&a);
  
  switch (a/10)
  {
  case 9:
  case 10:
    printf("A");
    break;
  case 8:
  printf("B");
  break;
 case 7:
 printf("C");
 break;
 case 6:
 printf("D");
 break;
 case 5:
 printf("E");
    break;
  }

    return 0;

    printf("hellp");
}