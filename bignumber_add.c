#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int c2n(char c)
{
    return (((int)c >= 48 && (int)c <= 57) ? (int)c - 48 : -1);
}
char n2c(int n)
{
    return ((n >= 0 && n <= 9) ? (char)(n + 48) : '\0');
}

void change(char *str)
{
    int len = strlen(str);
    int i;
    char temp;
    for (i = 0; i < len / 2; i++) {
        temp =  str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char *bignumber(char *bn1, char *bn2)
{
    int len1 = strlen(bn1);
    int len2 = strlen(bn2);
    int len = (len1 > len2 ? len1 : len2) + 1;
    char *ret = (char *)malloc((len + 1) * sizeof(char));
    int i = len1 - 1;
    int j = len2 - 1;
    int k = 0;
    int plus = 0; 

    while (i >= 0 && j >= 0) {
        ret[k++] = n2c((c2n(bn1[i]) + c2n(bn2[j]) + plus) % 10);
        plus = (c2n(bn1[i--]) + c2n(bn2[j--]) + plus) / 10;
    }
    while (i >=0 ) {
        ret[k++] = n2c((c2n(bn1[i]) + plus) % 10);
        plus = (c2n(bn1[i--]) + plus) / 10;
    }
    while (j >= 0) {
        ret[k++] = n2c((c2n(bn2[j]) + plus) % 10);
        plus = (c2n(bn2[j--]) + plus) / 10;
    }
    if (plus > 0) {
        ret[k++] = n2c(plus);
    }
    ret[k] = '\0';
    change(ret);

    return ret;
}

int main()
{
    char *bn1 = "8";
    char *bn2 = "2";
    char *sum;

    sum = bignumber(bn1, bn2);
    printf("%s\n", sum);

    if (sum) {
        free(sum);
    }
    return 0;
}