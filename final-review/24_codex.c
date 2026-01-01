#include <stdio.h>
#include <string.h>

typedef struct {
    char name[21];
    char gender[8];
    int annual;
} Emp;

static int is_male(const char *g)
{
    if (g == NULL || g[0] == '\0')
        return 0;
    if (g[0] == 'm' || g[0] == 'M')
        return 1;
    if (strcmp(g, "male") == 0 || strcmp(g, "MALE") == 0)
        return 1;
    if (strcmp(g, "man") == 0 || strcmp(g, "MAN") == 0)
        return 1;
    if (strcmp(g, "男") == 0)
        return 1;
    return 0;
}

int main(void)
{
    Emp employees[10];
    int total = 0;
    int male_count = 0, female_count = 0;
    int worst_male = -1, worst_female = -1;

    for (int i = 0; i < 10; i++) {
        int q1, q2, q3, q4;
        if (scanf("%20s %7s %d %d %d %d",
                  employees[i].name,
                  employees[i].gender,
                  &q1, &q2, &q3, &q4) != 6) {
            return 0;
        }

        employees[i].annual = q1 + q2 + q3 + q4;
        total += employees[i].annual;

        if (is_male(employees[i].gender)) {
            male_count++;
            if (worst_male == -1 || employees[i].annual <= employees[worst_male].annual)
                worst_male = i;
        } else {
            female_count++;
            if (worst_female == -1 || employees[i].annual <= employees[worst_female].annual)
                worst_female = i;
        }
    }

    if (male_count > 1)
        printf("%s %d\n", employees[worst_male].name, employees[worst_male].annual);
    if (female_count > 1)
        printf("%s %d\n", employees[worst_female].name, employees[worst_female].annual);

    int avg = total / 10;
    printf("%d\n", avg);

    for (int i = 0; i < 10; i++) {
        if (is_male(employees[i].gender) && employees[i].annual > avg)
            printf("%s %d\n", employees[i].name, employees[i].annual);
    }
    for (int i = 0; i < 10; i++) {
        if (!is_male(employees[i].gender) && employees[i].annual > avg)
            printf("%s %d\n", employees[i].name, employees[i].annual);
    }

    return 0;
}

