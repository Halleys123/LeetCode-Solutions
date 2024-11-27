#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if (!n)
        return;
    if (!m)
    {
        nums1 = nums2;
        return;
    }

    vector<int> ans;
    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
            ans.push_back(nums1[i++]);
        else
            ans.push_back(nums2[j++]);
    }
    while (i < m)
        ans.push_back(nums1[i++]);
    while (j < n)
        ans.push_back(nums2[j++]);

    nums1 = ans;
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