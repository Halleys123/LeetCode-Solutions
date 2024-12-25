#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

class Solution
{
public:
    int findGCD(vector<int> &nums)
    {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        return gcd(minNum, maxNum);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 5, 6, 9, 10};
    cout << s.findGCD(nums) << endl;
    return 0;
}