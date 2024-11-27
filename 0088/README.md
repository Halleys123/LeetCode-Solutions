# Merge Sorted Array

## Problem

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

## Solution

1. One - Use of extra space to store the merged array and then copy it back to `nums1`.
2. Two - Merge the two arrays in-place by starting from the end of `nums1` and comparing the elements from both arrays.

## Tags

- Array
- Sorting
