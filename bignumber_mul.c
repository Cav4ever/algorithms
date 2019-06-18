#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mul(const char *bn1, const char *bn2)
{
    int len1 = strlen(bn1);
    int len2 = strlen(bn2);
    int len = len1 + len2;
    int i, j, p1, p2, product, sum = 0;
    int *out = (int *)malloc(len * sizeof(int));
    char *ret = (char *)malloc(len * sizeof(char));

    memset(out, 0, len * sizeof(int));
    memset(ret, 0, len * sizeof(char));

    for (i = len1 - 1; i >= 0; i--) {
        for (j = len2 - 1; j >= 0; j--) {
            p1 = i + j;
            p2 = i + j + 1;
            product = (bn1[i] - '0') * (bn2[j] - '0');
            sum = product + out[p2];
            out[p1] += sum / 10;
            out[p2] = sum % 10;
        }
    }
    if (out[0] == 0) {
        for (i = 0; i < len - 1; i++) {
            out[i]  = out[i + 1];
            ret[i] = (char)(out[i] + '0');
        }
        ret[i] = '\0';
    }
    else {
        for (i = 0; i < len; i++) {
            ret[i] = (char)(out[i] + '0');
        }
        ret[i] = '\0';
    }
    if ((len1 == 1 && bn1[0] == '0') ||
        (len2 == 1 && bn2[0] == '0')) {
            ret[0] = '0';
            ret[1] = '\0';
        }
    free(out);
    return ret;
}

int main()
{
    char *bn1 = "123";
    char *bn2 = "0";
    char *result;

    result = mul(bn1, bn2);
    printf("%s\n", result);

    free(result);
    return 0;
}