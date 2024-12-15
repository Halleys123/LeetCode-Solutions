#include <iostream>
#include <vector>
#include <queue>

using namespace std;

double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
{
    auto compare = [](const pair<int, int> &a, const pair<int, int> &b)
    {
        double gainA = ((double)(a.first + 1) / (a.second + 1)) - ((double)a.first / a.second);
        double gainB = ((double)(b.first + 1) / (b.second + 1)) - ((double)b.first / b.second);
        return gainA < gainB;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

    for (const auto &c : classes)
    {
        pq.push({c[0], c[1]});
    }

    while (extraStudents > 0)
    {
        auto [pass, total] = pq.top();
        pq.pop();
        pq.push({pass + 1, total + 1});
        --extraStudents;
    }

    double totalAverage = 0.0;
    while (!pq.empty())
    {
        auto [pass, total] = pq.top();
        pq.pop();
        totalAverage += (double)pass / total;
    }

    return totalAverage / classes.size();
}

int main()
{
    vector<vector<int>> classes = {{1, 2}, {3, 5}, {2, 2}};
    int extraStudents = 2;
    cout << maxAverageRatio(classes, extraStudents) << endl;
    return 0;
}