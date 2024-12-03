// * Working 96.67% Beats
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string addSpaces(string s, vector<int> &spaces)
{
    char *ans = new char[spaces.size() + s.length() + 1];
    int j = 0;
    int aPos = 0;
    for (int pos = 0; pos < s.length(); pos++)
    {
        if (j < spaces.size() && pos == spaces[j])
        {
            ans[aPos++] = ' ';
            j += 1;
        }
        ans[aPos++] = s[pos];
    }
    ans[aPos] = '\0';
    return ans;
}

int main()
{
    string s = "HelloWhatAreYouDoing";
    vector<int> spaces = {5, 9, 12, 16};
    cout << addSpaces(s, spaces) << endl;
    return 0;
}