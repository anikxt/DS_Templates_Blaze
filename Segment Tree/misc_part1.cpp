#include <bits/stdc++.h>
typedef long long int ll;
#define gc getchar_unlocked
#define fab(i, a, b) for (int i = a; i <= b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
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

N arr
Q: ? L R K -> # of elements in range [L, R] <= K

*/

int n, q;
int arr[100100];

int t[400400];

void build(int index, int l, int r) {
   t[index] = 0;
   int mid = (l + r) / 2;
   build(index << 1, l, mid);
   build(index << 1 | 1, mid + 1, r);
}

void update(int index, int l, int r, int pos, int val) {
   if (pos < l or pos > r)
      return;
   if (l == r) {
      t[index] = val;
      return;
   }

   int mid = (l + r) / 2;
   update(index << 1, l, mid, pos, val);
   update(index << 1 | 1, mid + 1, r, pos, val);
   t[index] += t[index << 1] + t[index << 1 | 1];
}

int query(int index, int l, int r, int lq, int rq) {

}


void solve()
{
   cin >> n >> q;
   vector<pair<int, int>> vals;
   for (int i = 0; i < n; ++i)
   {
      cin >> arr[i];
      vals.push_back({arr[i], i});
   }

   sortall(vals);
   vector<pair<pii, pii>> queries;
   for (int i = 0; i < q; ++i)
   {
      int l, r, k;
      cin >> l >> r >> k;
      queries.push_back({k, i}, {l, r});
   }

   sortall(queries);
   int ans[q];
   build(1, 0, n - 1);
   int pos = 0;
   for (auto v : queries) {
      while (pos < vals.size() and vals[pos].F <= v.F.F) {
         update(1, 0, n - 1, vals[pos].S, 1);
         pos++;
      }
      ans[v.F.S] = query(1, 0, n - 1, v.S.F, v.S.S);
   }
   for (int i = 0; i < q; ++i)
   {
      cout << ans[i] << endl;
   }

   return;
}

int main()
{
   blaze;
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