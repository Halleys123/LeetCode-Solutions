// ! TIME LIMIT EXCEEDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string addSpaces(string s, vector<int> &spaces)
{
    for (int i = spaces.size() - 1; i >= 0; i--)
    {
        s.insert(spaces[i], " ");
    }
    return s;
}

int main()
{
    string s = "Hello";
    vector<int> spaces = {1, 3};
    cout << addSpaces(s, spaces) << endl;
    return 0;
}