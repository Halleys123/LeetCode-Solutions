#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> memo;

int lcs(string &s1, string &s2, int i, int j)
{
    if (i == s1.size() || j == s2.size())
    {
        return 0;
    }
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    if (s1[i] == s2[j])
    {
        memo[i][j] = 1 + lcs(s1, s2, i + 1, j + 1);
    }
    else
    {
        memo[i][j] = max(lcs(s1, s2, i + 1, j), lcs(s1, s2, i, j + 1));
    }
    return memo[i][j];
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    memo.resize(s1.size(), vector<int>(s2.size(), -1));
    return lcs(s1, s2, 0, 0);
}