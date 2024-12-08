int numIdenticalPairs(vector<int> &nums)
{
    int i = 0, j = 0, count = 0;
    for (i; i < nums.size() - 1; i++)
    {
        for (j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
                count += 1;
        }
    }
    return count;
}