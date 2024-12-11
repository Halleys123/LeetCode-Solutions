#include <vector>
#include <iostream>

using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> ans(2 * n, 0);
    int i = 0;
    while (i < 2 * n)
    {
        ans[i] = nums[i / 2];
        i += 2;
    }
    i = 1;
    while (i < 2 * n)
    {
        ans[i] = nums[n + i / 2];
        i += 2;
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;
    vector<int> ans = shuffle(nums, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}