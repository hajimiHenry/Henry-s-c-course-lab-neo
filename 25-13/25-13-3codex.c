
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
    char *p, *ps, *pt;
    if (t == NULL || *t == '\0') return s; /* 空子串：默认匹配到开头 */

    for (p = s; *p != '\0'; p++) {
        ps = p;
        pt = t;
        while (*ps != '\0' && *pt != '\0' && *ps == *pt) {
            ps++;
            pt++;
        }
        if (*pt == '\0') return p; /* t 全匹配完，返回在 s 中的起始位置 */
    }
    return NULL;
}
