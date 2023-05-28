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

1 -> Increase each value in range [a, b] by x.
2 -> Set each value in range [a, b] to x.
3 -> Calculate the sum of values in range [a, b].

sample test case ->
6 5
2 3 1 1 5 3
3 3 5
1 2 4 2
3 3 5
2 2 4 5
3 3 5

*/

ll n, q;
const ll N = 200200;
ll arr[N];

struct node {
   int l, r;
   ll sum;
   ll lazysum;
   int lazyset;
   node(int l = 0, int r = 0, ll sum = 0LL, ll lazysum = 0LL, int lazyset = 0)
   {
      l = l;
      r = r;
      sum = sum;
      lazysum = lazysum;
      lazyset = lazyset;
   };
};

node t[4 * N];

void pushup(int index) {
   t[index].sum = t[index << 1].sum + t[index << 1 | 1].sum;
}

void pushdown(int index) {
   if (t[index].lazyset) {
      t[index].sum = 1LL * (t[index].r - t[index].l + 1) * t[index].lazyset;
      if (t[index].l != t[index].r) {
         t[index << 1].lazyset = t[index].lazyset;
         t[index << 1].lazysum = 0;
         t[index << 1 | 1].lazyset = t[index].lazyset;
         t[index << 1 | 1].lazysum = 0;
      }
      t[index].lazyset = 0;
   }

   if (t[index].lazysum) {
      t[index].sum += 1LL * (t[index].r - t[index].l + 1) * (t[index].lazysum);
      if (t[index].l != t[index].r) {
         t[index << 1].lazysum += t[index].lazysum;
         t[index << 1 | 1].lazysum += t[index].lazysum;
      }
      t[index].lazysum = 0;
   }
}

#define mid ((l+r)>>1)
void build(int index, int l, int r) {
   t[index].l = l, t[index].r = r;
   if (l == r) {
      t[index].sum = arr[l];
      return;
   }

   build(index << 1, l, mid);
   build(index << 1 | 1, mid + 1, r);
   pushup(index);
}

void update(int index, int l, int r, int lq, int rq, int val, bool set) {
   pushdown(index);
   if (lq > r or l > rq)
      return;

   if (lq <= l and r <= rq) {
      if (!set)t[index].lazysum = val;
      else {
         t[index].lazyset = val;
      }
      pushdown(index);
      return;
   }

   update(index << 1, l, mid, lq, rq, val, set);
   update(index << 1 | 1, mid + 1, r, lq, rq, val, set);
   pushup(index);
}

ll query(int index, int l, int r, int lq, int rq) {
   pushdown(index);
   if (lq > r or l > rq)
      return 0;

   if (lq <= l and r <= rq) {
      return t[index].sum;
   }

   return query(index << 1, l, mid, lq, rq) + query(index << 1 | 1, mid + 1, r, lq, rq);
}
#undef mid

void solve()
{
   cin >> n >> q;
   for (int i = 0; i < n; ++i)
   {
      cin >> arr[i];
   }

   build(1, 0, n - 1);

   while (q--) {
      ll ch;
      cin >> ch;
      if (ch == 1) {
         ll l, r, v;
         cin >> l >> r >> v;
         l--, r--;
         update(1, 0, n - 1, l, r, v, false);
      } else if (ch == 2) {
         ll l, r, v;
         cin >> l >> r >> v;
         l--, r--;
         update(1, 0, n - 1, l, r, v, true);
      } else {
         int l, r;
         cin >> l >> r;
         l--, r--;
         cout << query(1, 0, n - 1, l, r) << endl;
      }
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