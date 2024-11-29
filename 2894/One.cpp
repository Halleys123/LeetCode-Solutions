#include <iostream>

using namespace std;

int differenceOfSums(int n, int m)
{
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i <= n; i++)
    {
        sum1 += i % m == 0 ? 0 : i;
    }
    for (int i = 0; i <= n; i++)
    {
        sum2 += i % m == 0 ? i : 0;
    }
    return sum1 - sum2;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << differenceOfSums(n, m) << endl;
    return 0;
}