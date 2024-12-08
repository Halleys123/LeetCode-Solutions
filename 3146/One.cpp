#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int findPermutationDifference(string s, string t)
{
    unordered_map<char, pair<int, int>> m;
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]].first = i;
        m[t[i]].second = i;
    }
    for (auto i : m)
    {
        sum += abs(i.second.first - i.second.second);
    }
    return sum;
}

int main()
{
    string s = "abc";
    string t = "bca";
    cout << findPermutationDifference(s, t) << endl;
    return 0;
}