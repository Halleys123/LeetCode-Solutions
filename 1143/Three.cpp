#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcs(string &s1, string &s2, int i, int j)
{
    if (i == s1.size() || j == s2.size())
    {
        return 0;
    }
    if (s1[i] == s2[j])
    {
        return 1 + lcs(s1, s2, i + 1, j + 1);
    }
    else
    {
        return max(lcs(s1, s2, i + 1, j), lcs(s1, s2, i, j + 1));
    }
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    return lcs(s1, s2, 0, 0);
}