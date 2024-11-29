#include <iostream>

using namespace std;

bool isDivisibleByM(int n, int m)
{
    return n % m == 0;
}

bool isNotDivisibleByM(int n, int m)
{
    return n % m != 0;
}

int diff(int upto, int m, bool (*predicate)(int, int))
{
    int sum = 0;
    for (int i = 0; i <= upto; i++)
    {
        if (predicate(i, m))
        {
            sum += i;
        }
    }
    return sum;
}

// Function to compute the difference of sums
int differenceOfSums(int n, int m)
{
    int sumDivisible = diff(n, m, isDivisibleByM);
    int sumNotDivisible = diff(n, m, isNotDivisibleByM);
    return sumDivisible - sumNotDivisible;
}

int main()
{
    int n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;
    cout << "Difference of sums: " << differenceOfSums(n, m) << endl;
    return 0;
}
