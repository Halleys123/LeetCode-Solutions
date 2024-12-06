#include <vector>
#include <iostream>

using namespace std;

vector<int> buildArray(vector<int> &nums)
{
    vector<int> ans;
    for (int i : nums)
    {
        ans.push_back(nums[i]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {0, 2, 1, 5, 3, 4};
    vector<int> ans = buildArray(nums);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}