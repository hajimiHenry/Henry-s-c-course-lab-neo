#include <stdio.h>
#define MAXN 20

void strmcpy( char *t, int m, char *s );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char t[MAXN], s[MAXN];
    int m;//从第m个字符开始复制
    
    scanf("%d\n", &m);
    ReadString(t);
    strmcpy( t, m, s );
    printf("%s\n", s);

    return 0;
}

/* 你的代码将被嵌在这里 */
void strmcpy( char *t, int m, char *s )
{
    if (m <= 0) {
        s[0] = '\0';
        return;
    }
    int len = 0;
    while (t[len]!='\0')
    {
       len ++; /* code */
    }
    
    if (m>len)
    {
       s[0]='\0';
       return; /* code */
    }
    
    char *p = t + (m - 1);
    while (*p != '\0') {
        *s++ = *p++;
    }
    *s = '\0';


}
