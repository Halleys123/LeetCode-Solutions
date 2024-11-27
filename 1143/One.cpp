#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> memo;

void lcs(string &s1, string &s2, int i, int j, int &length)
{
    if (i == s1.size() || j == s2.size())
    {
        return;
    }
    if (memo[i][j] != -1)
    {
        length = memo[i][j];
        return;
    }
    if (s1[i] == s2[j])
    {
        int temp_length = 0;
        lcs(s1, s2, i + 1, j + 1, temp_length);
        memo[i][j] = 1 + temp_length;
    }
    else
    {
        int temp_length1 = 0, temp_length2 = 0;
        lcs(s1, s2, i + 1, j, temp_length1);
        lcs(s1, s2, i, j + 1, temp_length2);
        memo[i][j] = max(temp_length1, temp_length2);
    }
    length = memo[i][j];
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    memo.resize(s1.size(), vector<int>(s2.size(), -1));
    int length = 0;
    lcs(s1, s2, 0, 0, length);
    cout << length << endl;
}