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
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
ll lcm(ll x, ll y) { ll res = x / __gcd(x, y); return (res * y);}
//=======================

/*

N <= 1e5
A[i] <= 1e9
D <= 1e9

N A:(3 5 7 1 2 1)

Find the longest subsequence A1, A2, A3,..., Ax

abs(A1 - A2) <= D

*/

int n, D, arr[100100];

map<ll, ll> compVal;

int t[400400];

#define mid ((l + r)>>1)
void update(int index, int l, int r, int pos, int val) {
   if (pos<l or pos > r)
      return;

   if (l == r) {
      t[index] = max(t[index], val);
      return;
   }

   update(index << 1, l, mid, pos, val);
   update(index << 1 | 1, mid + 1, r, pos, val);
   t[index] = max(t[index << 1], t[index << 1 | 1]);
}

int query(int index, int l, int r, int lq, int rq) {
   if (l > rq or lq > r )
      return 0;

   if (lq <= l and r <= rq) {
      // lq <= l <= r <= rq
      return t[index];
   }

   return max(query(index << 1, l, mid, lq, rq), query(index << 1 | 1, mid + 1, r, lq, rq));
}
#undef mid

void solve()
{
   cin >> n >> D;
   for (int i = 0; i < n; ++i)
   {
      cin >> arr[i];
      compVal[arr[i]];
   }

   int cnt = 0;
   for (auto &v : compVal) {
      v.second = cnt++;
   }

   int ans = 0;
   int dp[n];
   for (int i = 0; i < n; ++i)
   {
      int lo = arr[i] - D;
      int hi = arr[i] + D;

      auto it = compVal.upper_bound(hi);
      it--; hi = it->second;

      it = compVal.lower_bound(lo);
      lo = it->second;

      dp[i] = query(1, 0, cnt - 1, lo, hi) + 1;
      ans = max(ans, dp[i]);
      update(1, 0, cnt - 1, compVal[arr[i]], dp[i]);
   }

   cout << ans << endl;

   return;
}

signed main()
{
   blaze;
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