#include<stdio.h>
int main(void){
char x;
    scanf ("%c",&x);
switch (x) {
case 'A':
case 'a':
  printf("90");
  break;
case 'B':
case 'b':
  printf("80");
  break;
case 'C':
case 'c':
  printf("70");
  break;
case 'D':
case 'd':
  printf("60");
  break;
case 'E':
case 'e':
  printf("59");
  break;
default:
  printf("Data Error!");
  break;
}
return 0;}
