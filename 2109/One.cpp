// ! TIME LIMIT EXCEEDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string addSpaces(string s, vector<int> &spaces)
{
    int j = 0;
    for (int i : spaces)
    {
        s.insert(i + j, " ");
        j += 1;
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