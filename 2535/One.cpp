#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int differenceOfSum(vector<int> &nums)
{
    int digitSum = 0, elementSum = 0;
    for (int i : nums)
    {
        digitSum += i;
        while (i)
        {
            elementSum += i % 10;
            i /= 10;
        }
    }
    return abs(elementSum - digitSum);
}

int main()
{
    vector<int> nums = {123, 456, 789};
    cout << differenceOfSum(nums) << endl;
    return 0;
}