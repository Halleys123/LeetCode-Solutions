#include <iostream>
#include <string>
#include <vector>

using namespace std;

int scoreOfString(string s)
{
    int ans = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        ans += abs(s[i] - s[i + 1]);
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> v;
    sort(s.begin(), s.end());
    do
    {
        v.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    int maxScore = 0;
    for (int i = 0; i < v.size(); i++)
    {
        maxScore = max(maxScore, scoreOfString(v[i]));
    }
    cout << maxScore << endl;
    return 0;
}