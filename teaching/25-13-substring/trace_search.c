#include <stdio.h>
#include <string.h>

static int idx(const char *base, const char *p) {
    return (int)(p - base);
}

char *search_trace(char *s, char *t) {
    char *p, *ps, *pt;

    if (s == NULL) return NULL;
    if (t == NULL || *t == '\0') {
        printf("[edge] t is empty -> match at 0\n");
        return s;
    }

    printf("s=\"%s\"\n", s);
    printf("t=\"%s\"\n", t);

    for (p = s; *p != '\0'; p++) {
        printf("\n[try] start p=%d (s[%d]='%c')\n", idx(s, p), idx(s, p), *p);

        ps = p;
        pt = t;

        while (*ps != '\0' && *pt != '\0' && *ps == *pt) {
            printf("  [ok]  s[%d]='%c' == t[%d]='%c'\n",
                   idx(s, ps), *ps, idx(t, pt), *pt);
            ps++;
            pt++;
        }

        if (*pt == '\0') {
            printf("  [hit] t matched completely, return p=%d\n", idx(s, p));
            return p;
        }

        if (*ps == '\0') {
            printf("  [fail] s ended before t (s[%d]='\\0')\n", idx(s, ps));
        } else {
            printf("  [fail] mismatch at s[%d]='%c', t[%d]='%c'\n",
                   idx(s, ps), *ps, idx(t, pt), *pt);
        }
    }

    printf("\n[miss] not found\n");
    return NULL;
}

int main(void) {
    char s[128], t[128];

    /* 为了教学直观：用 fgets 读整行，去掉结尾换行 */
    if (!fgets(s, sizeof(s), stdin)) return 0;
    if (!fgets(t, sizeof(t), stdin)) return 0;
    s[strcspn(s, "\r\n")] = '\0';
    t[strcspn(t, "\r\n")] = '\0';

    char *pos = search_trace(s, t);
    if (pos) {
        printf("\nresult index = %d\n", (int)(pos - s));
    } else {
        printf("\nresult index = -1\n");
    }
    return 0;
}

