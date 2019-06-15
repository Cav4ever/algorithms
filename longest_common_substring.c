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
    for (i = 0; i < len1; i++) {
       for (j = 0; j < len2; j++) {
           if (str1[i] != str2[j]) {
              lcs[i][j] = 0;
           } else if (i == 0 || j == 0) {
               lcs[i][j] = 1;
               ret = (ret < 1 ? 1 : ret);
           } else {
               lcs[i][j] = lcs[i -1][j - 1] + 1;
               ret = (ret < lcs[i][j] ? lcs[i][j] : ret);
           }
       } 
    }
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
