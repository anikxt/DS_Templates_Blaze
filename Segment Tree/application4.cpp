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

int n;
int h[100100], p[100100];
const int N = 1e5;

int t[400400];

int merge(int a, int b) {
   return a + b;
}

void build(int index, int l, int r) {
   if (l == r) {
      t[index] = 1;
      return;
   }

   int mid = (l + r) / 2;
   build(index * 2, l, mid);
   build(index * 2 + 1, mid + 1, r);
   t[index] = merge(t[index * 2], t[index * 2 + 1]);
}

void update(int index, int l, int r, int pos, int par) {
   if (pos < l or pos > r)
      return;

   if (l == r) {
      t[index] = par;
      return;
   }

   int mid = (l + r) / 2;

   update(index * 2, l, mid, pos, par);
   update(index * 2 + 1, mid + 1, r, pos, par);
   t[index] = merge(t[index * 2], t[index * 2 + 1]);
}

int query(int index, int l, int r, int k) {
   if (l == r) {
      return l;
   }

   int mid = (l + r) / 2;
   if (k <= t[2 * index])
      query(index * 2, l, mid, k);
   else query(index * 2 + 1, mid + 1, r, k - t[index * 2]);
}

void solve()
{
   cin >> n;
   const int N = 1e5;

   for (int i = 0; i < n; ++i)
      cin >> h[i];

   for (int i = 0; i < n; ++i)
      cin >> p[i];

   vector<pii> pr(n);
   for (int i = 0; i < n; ++i)
   {
      pr[i] = make_pair(h[i], p[i]);
   }

   sortall(pr);
   build(1, 0, n - 1);

   vector<int> ans(n);

   for (int i = 0; i < n; ++i)
   {
      int idx = query(1, 0, n - 1, pr[i].second + 1);
      deb(idx);
      ans[idx] = pr[i].first;
      update(1, 0, n - 1, idx, 0);
   }

   for (int i = 0; i < n; ++i)
   {
      cout << ans[i] << " ";
   }
   return;
}

int main()
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