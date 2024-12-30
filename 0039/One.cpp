/**
 * @file This file is a standalone file that should not be imported in @root/main.cpp
 * as this file contains a main.cpp function.
 */

#include <vector>
#include <iostream>

using namespace std;

void sumFunc(int i, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &temp)
{
    if (i >= candidates.size())
        return;
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (target < 0)
    {
        return;
    }
    temp.push_back(candidates[i]);
    sumFunc(i, target - candidates[i], candidates, ans, temp);
    temp.pop_back();
    sumFunc(i + 1, target, candidates, ans, temp);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;

    sumFunc(0, target, candidates, ans, temp);
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 4, 6, 7};
    int target = 7;
    vector<vector<int>> ans = combinationSum(arr, target);
    for (auto i : ans)
    {
        cout << "[ ";
        for (auto j : i)
        {
            cout << j;
            if (j != i.back())
            {
                cout << ", ";
            }
        }
    }
}
