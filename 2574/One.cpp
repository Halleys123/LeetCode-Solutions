#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        vector<int> left_sum;
        vector<int> right_sum(nums.size(), 0);
        left_sum.push_back(0);
        for (int i = 1; i < nums.size(); i++)
        {
            left_sum.push_back(left_sum[i - 1] + nums[i - 1]);
        }

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            right_sum[i] = right_sum[i + 1] + nums[i + 1];
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(abs(left_sum[i] - right_sum[i]));
        }
        return ans;
    }
};