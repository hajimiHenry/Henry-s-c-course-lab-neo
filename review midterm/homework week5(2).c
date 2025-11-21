#include<stdio.h>
//思路：先读入要写几行，和有几个字母
//然后看第一个是不是a

//因该把是不是a放在中间，遇到a 了就变回z
//再去减减

//如果是a：回到z
//如果不是a：往回看
int main(void){
    int n;
    char first;
    scanf("%d %c",&n,&first);

    for (int i = 1; i <= n; i++)//外层控制行数,
    {
        char cha=first;
        for (int k = 0; k <i ; k++)//内层控制一行有几个
        {
            printf("%c",cha);
            if (cha=='A')
            {
              cha='Z';  /* code */
            }
            else{
                cha--;
            }
        }
        printf("\n");
    }
    return 0;
}