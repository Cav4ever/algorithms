#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ReverseWords(char *s)
{
    int len, i, j, count = 0;
    char *temp;
    
    len = strlen(s) - 1;
    temp = (char *)malloc((len + 1) * sizeof(char));

    for (i = len - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            j = i + 1;
            while (s[j] != ' '  && j < len) {
                temp[count++] = s[j];
                j++;
            }
            if (s[i + 1] != ' ' && (i + 1) < len) {
                temp[count++] = ' ';
            }
        }
    }
    for (i = 0; i < len, s[i] != ' '; i++) {
        temp[count++] = s[i];
    }
    if (s[0] = ' ') {
        temp[count - 1] = '\0';
        for (i = 0; i < count; i++) {
            s[i] = temp[i];
        }
    } else {
        for (i = 0; i < count; i++) {
            s[i] = temp[i];
        }
        s[i] = '\0';
    }    
    
    free(temp);
}

int main()
{
    char s[1000] = "   I     am      a    boy    ";
    //fgets(s, 1000, stdin);
    ReverseWords(s);
    printf("%s\n", s);
    printf("%d\n", (int)strlen(s));
    return 0;
}