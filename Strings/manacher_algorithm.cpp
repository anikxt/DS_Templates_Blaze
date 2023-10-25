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

/**
   works in armotized O(n) TC
**/

struct manacher {
   vector<int> p;

   void run_manacher(string s) {
      int n = s.size();
      p.assign(n, 1);
      // left and right pointers of a palindrome
      int l = 1, r = 1;
      for (int i = 1; i < n; ++i)
      {
         // bounding box optimisation
         p[i] = max(0, min(r - i, p[l + r - i]));
         while (i + p[i] < n and i - p[i] >= 0 and s[i + p[i]] == s[i - p[i]]) {
            p[i]++;
         }

         if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
         }
      }

      for (auto v : p) {
         cout << v << " ";
      }
      cout << endl;
   }


   void build(string s) {
      string t;
      for (auto v : s) {
         t += string("#") + v;
      }
      run_manacher(t + '#');
   }

   /**
      abbabba => #a#b#b#a#b#b#a#
      cen = 1, odd = 1 => a |b| babba  = 1 (b)
      cen = 1, odd = 0 => ab | babba  = 4 (abba)
   **/
   int getLongest(int cen, bool odd) {
      int pos = 2 * cen + 1 + (!odd);
      return p[pos] - 1;
   }

   bool checkPalin(int l, int r) {
      if ((r - l + 1) <= getLongest((l + r) / 2, l % 2 == r % 2)) {
         return 1;
      } else {
         return 0;
      }
   }
} m;

void solve()
{
   string s = "babbabbabc";
   m.build(s);
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