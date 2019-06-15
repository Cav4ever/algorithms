#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longest(const char *str1, const char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **lcs = (int **)malloc(len1 * sizeof(int *));
    int i, j;
    int ret = 0;
    for (i = 0; i < len1; i++) {
        lcs[i] = (int *)malloc(len2 * sizeof(int));
    }
    if (str1[0] == str2[0]) {
            lcs[0][0] = 1;
        } else {
            lcs[0][0] = 0;
    }
    for (i = 1; i < len1; i++) {
        if (str1[i] == str2[0]) {
            lcs[i][0] = 1;
        } else {
            lcs[i][0] = lcs[i - 1][0];
        }
    }
    for (j = 1; j < len2; j++) {
        if (str1[0] == str2[j]) {
            lcs[0][j] = 1;
        } else {
            lcs[0][j] = lcs[0][j - 1];
        }
    }
    for (i = 1; i < len1; i++) {
       for (j = 1; j < len2; j++) {
           if (str1[i] == str2[j]) {
               lcs[i][j] = lcs[i - 1][j - 1] + 1;
           } else {
               lcs[i][j] = (lcs[i - 1][j] > lcs[i][j - 1] ? lcs[i - 1][j] : lcs[i][j - 1]);
           }
       } 
    }
    ret = lcs[len1 - 1][len2 -1];
    for (i = 0; i < len1; i++) {
        free(lcs[i]);
    }
    free(lcs);
    return ret;
}

int main()
{
    char *str1 = "blue";
    char *str2 = "clues";
    int len = longest(str1, str2);
    printf("lcs of %s and %s is %d\n", str1, str2, len);
    return 0;
}
