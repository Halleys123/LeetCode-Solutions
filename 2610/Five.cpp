// Sorting the array nlogn

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> findMatrix(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int num : nums)
    {
        bool placed = false;
        for (auto &row : ans)
        {
            if (row.back() != num)
            {
                row.push_back(num);
                placed = true;
                break;
            }
        }
        if (!placed)
        {
            ans.push_back({num});
        }
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