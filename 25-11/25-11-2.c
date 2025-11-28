#include<stdio.h>
int half(int a[10], int x);

int main( )                                  
{ int a[10],x,i,pos;  
  for(i=0; i<10; i++)
      scanf("%d",&a[i]);
  scanf("%d",&x);
  pos=half(a,x);
  printf("%d",pos);             
  return 0;
}
/* 你写的函数将嵌在这里 */
int half(int a[10], int x){

int right=9;
int left=0;

while (left<=right)
{
    int mid=(left+right)/2;

    if (a[mid]==x)
    {
        return mid;
    }
    if (a[mid]>x)
    {
       right=mid-1; /* code */
    }
    if (a[mid]<x)
    {
        left=mid+1;
    }   
}
return -1;

}