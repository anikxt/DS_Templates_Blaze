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
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i)
  {
    // cout << "Case #" << i << ": ";
    solve();
  }
  // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}