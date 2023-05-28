#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
typedef long long int ll;
#define gc getchar_unlocked
#define fab(i, a, b) for (int i = a; i <= b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define clr(x, y) memset(x, y, sizeof(x))
#define sortall(x) sort(all(x))
#define vll vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;

const int MOD = 1e9 + 7;
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
  cout << rec(1, 0, 0) << endl;
  return;
}

int main()
{
  blaze;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; ++i)
  {
    // cout << "Case #" << i << ": ";
    solve();
  }
  // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}