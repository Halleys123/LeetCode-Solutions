#include <iostream>

using namespace std;

int differenceOfSums(int n, int m)
{
    int notDivisible = 0;
    int divisible = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i % m == 0)
        {
            divisible += i;
        }
        else
        {
            notDivisible += i;
        }
    }
    int result = notDivisible - divisible;
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << differenceOfSums(n, m) << endl;
    return 0;
}