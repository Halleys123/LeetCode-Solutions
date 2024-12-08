#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int findPermutationDifference(string s, string t)
{
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        const int diff = (i - t.find(s[i]));
        count += std::abs(diff);
    }
    return count;
}

int main()
{
    string s = "abc";
    string t = "bca";
    cout << findPermutationDifference(s, t) << endl;
    return 0;
}