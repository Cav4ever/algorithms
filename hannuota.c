#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int count = 1;

void solution(int n, char src, char dst)
{
    char temp = 'a' + 'b' + 'c' - src -dst;
    if (n > 1) {
        solution(n - 1, src, temp);
        printf("%d\t move %d from %c to %c\n", count++, n, src, dst);
        solution(n - 1, temp, dst);
    } else {
        printf("%d\t move %d from %c to %c\n", count++, n, src, dst);
    }

}

int main(int argc, char **argv)
{
    char *stop = NULL;
    int n;

    if (2 != argc) {
        printf("usage: ./a.out n.\n");
        exit(1);
    }

    n = strtoul(argv[1], &stop, 0);
    if (*stop != '\0' || ERANGE == errno) {
        printf("Error n arg: %s\n", argv[1]);
        return -1;
    }

    solution(n, 'a', 'c');
    return 0;
}
