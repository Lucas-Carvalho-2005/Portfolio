#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char s[] = "Exame";
    char **pps;
    char *ps;

    ps = s;
    pps = &ps;

    printf("%c | %c | %c \n", s[0], *ps, **pps); // E | E | E
    printf("%c | %c | %c \n", s[1], *(ps+2), *(*pps+3)); // x | a | m
    printf("%c | %c | %c \n", s[strlen(s)-1], *(ps+4), *(*pps+4)); // e | e | e
    printf("%d | %d | %d \n", strlen(s), strlen(ps), strlen(*pps)); // 5 | 5 | 5
    printf("\n %d \n %d \n %d \n", &s[0], &ps, &pps); // ??? | E | E
}
