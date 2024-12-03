// * Working 90.06% Beats

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string addSpaces(string s, vector<int> &spaces)
{
    int spaceSize = spaces.size();
    int stringSize = s.size();

    char *ans = new char[spaceSize + stringSize + 1];

    int j = 0;
    int aPos = 0;
    int pos = 0;
    while (pos < stringSize)
    {
        if (j < spaceSize && pos == spaces[j])
        {
            ans[aPos++] = ' ';
            j += 1;
        }
        ans[aPos++] = s[pos++];
    }
    ans[aPos] = '\0';
    return ans;
}

int main()
{
    string s = "Hello";
    vector<int> spaces = {1, 3};
    cout << addSpaces(s, spaces) << endl;
    return 0;
}