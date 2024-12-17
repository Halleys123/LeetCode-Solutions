#include <vector>
#include <queue>

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> freq(26, 0);
        for (char i : ransomNote)
        {
            freq[i - 'a'] += 1;
        }
        for (char i : magazine)
        {
            freq[i - 'a'] -= 1;
        }
        for (char i : ransomNote)
        {
            if (freq[i - 'a'] >= 1)
                return false;
        }
        return true;
    }
};