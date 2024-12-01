#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool checkIfExist(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j && arr[i] == 2 * arr[j])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {10, 2, 5, 3};
    cout << checkIfExist(arr) << endl;
    return 0;
}