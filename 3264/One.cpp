#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < nums.size(); i++)
    {
        q.push({nums[i], i});
    }
    while (k)
    {
        pair<int, int> top = q.top();
        q.pop();
        top.first *= multiplier;
        q.push(top);
        k -= 1;
    }
    while (!q.empty())
    {
        nums[q.top().second] = q.top().first;
        q.pop();
    }
    return nums;
}