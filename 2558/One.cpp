#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long pickGifts(vector<int> &gifts, int k)
{
    priority_queue<int> maxHeap(gifts.begin(), gifts.end());
    long long sum = 0;

    while (k-- > 0 && !maxHeap.empty())
    {
        int maxVal = maxHeap.top();
        maxHeap.pop();
        int reducedVal = floor(sqrt(maxVal));
        maxHeap.push(reducedVal);
    }

    while (!maxHeap.empty())
    {
        sum += maxHeap.top();
        maxHeap.pop();
    }

    return sum;
}

int main()
{
    vector<int> gifts = {4, 3, 2, 6};
    int k = 3;
    long long result = pickGifts(gifts, k);
    return 0;
}