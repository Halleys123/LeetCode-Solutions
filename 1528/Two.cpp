#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        for (int i = 0; i < indices.size(); i++)
        {
            char temp = s[indices[i]];
            s[indices[i]] = s[i];
            s[i] = temp;
            int t = indices[indices[i]];
            indices[indices[i]] = indices[i];
            indices[i] = t;
            if (indices[i] != i)
                i = 0;
        }
        return s;
    }
};

int main()
{
    Solution s;
    vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};
    cout << s.restoreString("codeleet", indices) << endl;
    return 0;
}