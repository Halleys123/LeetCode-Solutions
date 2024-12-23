#include <vector>
#include <iostream>

using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> ans(2 * n, 0);

    for (int i = 0, j = n, k = 0; i < n; i++, j++, k += 2)
    {
        ans[k] = nums[i];
        ans[k + 1] = nums[j];
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