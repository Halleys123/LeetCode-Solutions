#include <iostream>
#include <vector>

using namespace std;

int maximumWealth(vector<vector<int>> &accounts)
{
    int max_val = INT_MIN, sum = 0;
    for (auto i : accounts)
    {
        sum = 0;
        for (auto j : i)
        {
            sum += j;
        }
        max_val = max(max_val, sum);
    }
    return max_val;
}

int main()
{
    vector<vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}};
    cout << maximumWealth(accounts) << endl;
    return 0;
}