#include <iostream>
#include <vector>

using namespace std;

int isPrefixOfWord(string s, string w)
{
    int wordIndex = 1;
    int i = 0;

    while (i < s.length())
    {
        if (s.substr(i, w.length()) == w)
        {
            return wordIndex;
        }

        while (i < s.length() && s[i] != ' ')
            i++;
        while (i < s.length() && s[i] == ' ')
            i++;

        wordIndex++;
    }
    return -1;
}

int main()
{
    string s = "i love eating burger";
    string w = "burg";
    cout << isPrefixOfWord(s, w) << endl;
    return 0;
}
