#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int n;
int t[1001];
int s[1001];
int x, k;

int dp[101][101][101];

int rec(int level, int time_taken, int item_taken)
{ // max skill i can make from [level--n-1]... if [0..level-1 is decided]... and parameters means from [0..level-1]
  // level -> current item in [0..level-1]

  // pruning

  // base case
  if (level == n)
  {
    return 0;
  }

  // cache check
  if (dp[level][time_taken][item_taken] != -1)
    return dp[level][time_taken][item_taken];

  // compute / transition
  int ans = rec(level + 1, time_taken, item_taken);
  if (time_taken + t[level] <= x and item_taken + 1 <= k)
  {
    ans = max(ans, s[level] + rec(level + 1, time_taken + t[level], item_taken + 1));
  }

  // save and return
  return dp[level][time_taken][item_taken] = ans;
}

void solve()
{
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> t[i] >> s[i];
  }
  cin >> x >> k;
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0, 0) << endl;
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
