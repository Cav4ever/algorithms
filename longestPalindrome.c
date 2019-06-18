int isPal(char* s, int start, int end) {
    int i;
    for (i = start; i < start + (end - start + 1)/2; i++) {
        if (s[i] != s[start + end - i]) {
            return 0;
        }
    }
    return 1;
}

char* longestPalindrome(char* s) {
    int len = strlen(s), i, j, start = 0, end = 0;
    char* res = (char*) malloc(1001*sizeof(char));
    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (isPal(s, i, j)) {
                if ((j - i) > (end - start)) {
                    start = i;
                    end = j;
                }
            }
        }
    }
    for (i = 0; i < end - start + 1; i++) {
        res[i] = s[start + i];
    }
    res[i] = '\0';
    return res;
}