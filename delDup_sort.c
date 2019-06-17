#include <stdio.h>
#include <stdlib.h>

void merge(const int *seq1, int len1, const int *seq2, int len2, int *out)
{
    int count = 0, i = 0, j = 0;
    out = (int *)malloc((len1 + len2) * sizeof(int));
    while (i < len1 && j < len2) {
        if (seq1[i] < seq2[j]) {
            out[count++] = seq1[i++];
        } else if (seq1[i] > seq2[j]) {
            out[count++] = seq2[j++];
        } else {
            out[count++] = seq1[i++];
            j++;
        }
    }
    while (i < len1) {
        out[count++] = seq1[i++];
    }
    while (j < len2) {
        out[count++] = seq2[j++];
    }
    for (i = 0; i < count; i++) {
        printf("%d\n", out[i]);
    }
}

int main()
{
    int seq1[5] = {1, 3, 4, 7, 9};
    int seq2[3] = {2, 4, 10};
    int *out;

    merge(seq1, 5, seq2, 3, out);
    free(out);

    return 0;
}
