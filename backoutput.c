#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000] = {'\0'};
    int len, i, j;

    fgets(str, 1000, stdin);
    len = strlen(str) - 1;

    for (i = len - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            j = i + 1;
            while (str[j] != ' '  && j < len) {
                printf("%c", str[j]);
                j++;
            }
            printf(" ");
        }
    }
    for (i = 0; i < len, str[i] != ' '; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}