// * Working
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string addSpaces(string s, vector<int> &spaces)
{
    string ans = "";
    int j = 0;
    for (int pos = 0; pos < s.length(); pos++)
    {
        if (j < spaces.size() && pos == spaces[j])
        {
            ans += " ";
            j += 1;
        }
        ans += s[pos];
    }
    return ans;
}

int main()
{
    string s = "Hello";
    vector<int> spaces = {1, 3};
    cout << addSpaces(s, spaces) << endl;
    return 0;
}