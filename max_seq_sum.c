#include <stdio.h>

int sum(int *nums, int n)
{
    int ret = -1;
    int sum1, i;

    if (n < 1) {
        return ret;
    }

    ret = nums[0];
    sum1 = nums[0];
    printf("sum1=%d\n", sum1);

    for (i = 1; i < n; i++) {
        sum1= nums[i] + (sum1 > 0 ? sum1 : 0);
        printf("sum%d=%d\n", (i+1), sum1);
        ret = sum1 > ret ? sum1 : ret;
    }

    return ret;
}

int main()
{
    int res;
    int nums[8] = {-2, 6, -1, 5, 4, -7, 2, 3};
    res = sum(nums, 8);
    printf("sum=%d\n", res);
    return 0;
}
