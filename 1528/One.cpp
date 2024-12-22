#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        string b = s;
        for (int i = 0; i < indices.size(); i++)
        {
            b[indices[i]] = s[i];
        }
        return b;
    }
};