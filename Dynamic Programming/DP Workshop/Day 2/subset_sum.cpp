#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// subset sum exactly equal to T

int n;
int t;
int x[101];

int dp[105][10005];

int rec(int level, int taken) {
  // pruning
  if (taken > t)
    return 0;

  //base case
  if (level == n) {
    if (taken == t)
      return 1;
    else return 0;
  }

  // cache check
  if (dp[level][taken] != -1)
    return dp[level][taken];


  // compute
  int ans = 0;
  if (rec(level + 1, taken)) {
    ans = 1;
  } else if (rec(level + 1, taken + x[level])) {
    ans = 1;
  }

  // save and return
  return dp[level][taken] = ans;
}

void solve()
{
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> x[i];
  }
  cin >> t;
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0);
  return;
}

int main()
{
  blaze;
  int _t = 1;
  cin >> _t;
  while (_t--) {
    solve();
  }
  return 0;
}
