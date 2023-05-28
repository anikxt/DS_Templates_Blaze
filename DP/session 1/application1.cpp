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

// palindrome partitioning

int n;
string s;

int dp1[1010][1010];
// 0-based indexing
int rec1(int l, int r) { // check palindrome
   if (l >= r)
      return 1;

   if (dp1[l][r] != -1)
      return dp[l][r];

   int ans = 0;
   if (s[l - 1] == s[r - 1] and rec1(l + 1, r - 1))
      ans = 1;

   return dp1[l][r] = ans;
}

int dp2[1010];
// 1-based indexing
int rec2(int i) { // min cuts for [1...i]
   if (i == 0) {
      return -1;
   }

   if (dp2[i] != -1) {
      return dp[i];
   }

   int ans = 1e9;
   for (int j = 0; j < i; ++j)
   {
      if (rec1(j + 1, i)) {
         ans = min(ans, rec2(j) + 1);
      }
   }

   return dp2[i] = ans;
}

void solve()
{
   cin >> n;
   cin >> s;
   memset(dp1, -1, sizeof(dp1));
   memset(dp2, -1, sizeof(dp2));
   cout << rec2(n) << endl;
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