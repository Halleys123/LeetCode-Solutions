
#include <iostream>
#include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int m = INT_MIN;
    for (int i = 0; i < candies.size(); i++)
    {
        m = max(m, candies[i]);
    }
    for (int i = 0; i < candies.size(); i++)
    {
        candies[i] = candies[i] + extraCandies >= m;
    }
    return vector<bool>(candies.begin(), candies.end());
}

int main()
{
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> ans = kidsWithCandies(candies, extraCandies);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}