#include <string>
#include <iostream>

using namespace std;

string stringHash(string s, int k)
{
    int sum = 0;

    for (int i = 0; i < s.length() / k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            sum += s[j + i * k] - 'a';
        }
        sum = sum % 26;
        s[i] = sum + 'a';
        sum = 0;
    }

    return s.substr(0, s.length() / k);
}

int main()
{
    string s;
    int k;
    cin >> s >> k;
    cout << stringHash(s, k) << endl;
    return 0;
}