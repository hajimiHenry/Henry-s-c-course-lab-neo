
#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ); /* 裁判提供，细节不表 */

int main()
{
    char s[MAXS], t[MAXS], *pos;
    
    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
char *search( char *s, char *t )
{
    //先判断要比较的是不是空串
    if (t==NULL||*t=='\0')
    {
        return s;
    }
    //现在不是空船了
    char *pt;
    char *ps;
    char *p;

    for (p=s; *p!='\0'; p++)                        
    {
        pt=t;
        ps=p;
        //开始做匹配，配上了，两边相等
        while (*ps!='\0'&&*pt!='\0'&&*ps==*pt)
        {
            ps++;
            pt++;
        }
        if (*pt=='\0')
        {
            return p;
        }
    }
 
    return NULL;
}


