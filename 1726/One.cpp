#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int fact(int n)
    {
        int res = 1;
        for (int i = n; i > 1; i--)
        {
            res *= i;
        }
        return res;
    }
    int tupleSameProduct(vector<int> &nums)
    {
        vector<vector<int>> prod(nums.size(), vector<int>(nums.size(), 0));
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                prod[i][j] = nums[i] * nums[j];
                if (nums[j] != nums[i])
                    map[prod[i][j]] += 1;
            }
        }
        for (auto i : prod)
        {
            for (int j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }

        int count = 0;
        for (auto &i : map)
        {
            if (i.second >= 2)
                count += fact(i.second);
        }

        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 4, 6, 8, 12};
    sol.tupleSameProduct(nums);
    return 0;
}