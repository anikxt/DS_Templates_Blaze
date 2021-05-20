#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fab(a, b, i) for (int i = a; i < b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define f first
#define se second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
//=======================
const int N = 2e6 + 13, M = N;
//=======================
int a[N];
int c, k, m, n, t, x, y;
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
      sum = max(nums[i], sum + nums[i]);
      best = max(best, sum);
    }
    return best;
  }
};
