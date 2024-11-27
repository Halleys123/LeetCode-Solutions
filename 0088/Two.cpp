#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        int temp = nums1[i];
        if (temp > nums2[j])
        {
            nums1.insert(nums1.begin() + i, nums2[j]);
            nums1.pop_back();
            j++;
        }
        else if (temp <= nums2[j])
        {
            i++;
        }
    }
    while (j < n)
    {
        nums1.insert(nums1.begin() + i, nums2[j]);
        nums1.pop_back();
        i++;
        j++;
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);

    for (int i = 0; i < nums1.size(); i++)
        cout << nums1[i] << " ";
    cout << endl;

    return 0;
}