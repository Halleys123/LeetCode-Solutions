#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char findTheDifference(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int a = 0;
    for (a = 0; a < t.length(); a++)
    {
        if (s[a] != t[a])
            return t[a];
    }
    return t[a];
}

int main()
{
    string a = "abde";
    string b = "daecb";
    cout << findTheDifference(a, b) << endl;
    return 0;
}