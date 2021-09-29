#include <bits/stdc++.h>
using namespace std;
//=======================

// 53. Maximum Subarray

/* Given an array of n numbers, our task is to calculate the maximum subar-
ray sum, i.e., the largest possible sum of a sequence of consecutive values in
the array. The problem is interesting when there may be negative values in
the array. */

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int best = INT_MIN, sum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      sum = max(sum + nums[i], nums[i]);
      best = max(best, sum);
    }
    return best;
  }
};
