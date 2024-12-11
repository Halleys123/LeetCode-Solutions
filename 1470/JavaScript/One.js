/**
 * @param {number[]} nums
 * @param {number} n
 * @return {number[]}
 */
var shuffle = function (nums, n) {
  let ans = [];
  for (let i = 0; i < 2 * n; i += 2) {
    ans[i] = nums[i / 2];
  }
  for (let i = 1; i < 2 * n; i += 2) {
    ans[i] = nums[n + ((i / 2) | 0)];
  }
  return ans;
};
