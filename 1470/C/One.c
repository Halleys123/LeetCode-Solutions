int *shuffle(int *nums, int numsSize, int n, int *returnSize)
{
    int *ans = (int *)malloc(2 * n * sizeof(int));
    int i = 0;
    while (i < 2 * n)
    {
        ans[i] = nums[i / 2];
        ans[i + 1] = nums[n + i / 2];
        i += 2;
    }
    *returnSize = 2 * n;
    return ans;
}
