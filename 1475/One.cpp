#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int size = prices.size();
        vector<int> ans(size, 0);
        for (int i = 0; i < size - 1; i++)
        {
            int cur = prices[i];
            int lesser = 0;
            for (int j = i + 1; j < size; j++)
            {
                if (prices[j] <= prices[i])
                {
                    lesser = prices[j];
                    break;
                }
            }
            ans[i] = cur - lesser;
        }
        ans[size - 1] = prices[size - 1];
        return ans;
    }
};