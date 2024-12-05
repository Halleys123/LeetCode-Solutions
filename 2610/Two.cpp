
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<vector<int>> findMatrix(vector<int> &nums)
{
    unordered_map<int, int> map;
    int max = 1;
    for (int i : nums)
    {
        map[i] += 1;
        if (max < map[i])
            max = map[i];
    }
    vector<vector<int>> ans(max, vector<int>(0));
    for (int i : nums)
    {
        ans[map[i] - 1].push_back(i);
        map[i] -= 1;
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