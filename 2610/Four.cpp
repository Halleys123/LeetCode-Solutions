// Single Loop

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> findMatrix(vector<int> &nums)
{
    unordered_map<int, int> freq;
    vector<vector<int>> ans;

    for (int num : nums)
    {
        int count = ++freq[num];
        if (ans.size() < count)
        {
            ans.push_back({});
        }
        ans[count - 1].push_back(num);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 3, 3};
    vector<vector<int>> ans = findMatrix(nums);
    for (auto i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}