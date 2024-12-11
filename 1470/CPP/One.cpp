#include <vector>
#include <iostream>

std::vector<int> shuffle(std::vector<int> &nums, int n)
{
    std::vector<int> ans(2 * n, 0);
    int i = 0;
    while (i < 2 * n)
    {
        ans[i] = nums[i / 2];
        ans[i + 1] = nums[n + i / 2];
        i += 2;
    }
    return ans;
}

int main()
{
    std::vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;
    std::vector<int> ans = shuffle(nums, n);
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " ";
    }
    return 0;
}