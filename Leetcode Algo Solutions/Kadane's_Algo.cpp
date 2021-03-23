#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; ++i)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define elif else if
#define co cout
#define endl '\n'
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================
const int MOD = 1'000'000'007;
const int N = 2e6 + 13, M = N;
//=======================
vi g[N];
int a[N];
int c, k, m, n, t, x, y;
//=======================

// 53. Maximum Subarray

/* Given an array of n numbers, our task is to calculate the maximum subar-
ray sum, i.e., the largest possible sum of a sequence of consecutive values in
the array. The problem is interesting when there may be negative values in
the array. */

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int best = INT_MIN, sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum = max(nums[i], sum + nums[i]);
      best = max(best, sum);
    }
    return best;
  }
};
