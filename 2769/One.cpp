#include <iostream>

using namespace std;

int theMaximumAchievableX(int num, int t)
{
    return num + 2 * t;
}

int main()
{
    int num = 3, t = 2;
    cout << theMaximumAchievableX(num, t) << endl;
    return 0;
}