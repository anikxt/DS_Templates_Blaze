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

// Knights - 1 / K Knights

int n, k;
int ans;

int board[14][14];

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2};


bool check1(int i, int j) {
   if (board[i][j] == 1)return 0;
   for (int pos = 0; pos < 8; ++pos)
   {
      int nx = i + dx[pos];
      int ny = j + dy[pos];
      // (nx, ny) -> are the cells getting attacked
      if ((nx >= 0 and nx < n) and (ny >= 0 and ny < n) and board[nx][ny] == 1)return 0;
   }
   return 1;
}

void rec(int level, int lastx, int lasty) { // level = no. of knights placed
   if (level == k) {
      ans++;
      // board gives the solution
      return;
   }

   // choices
   for (int i = lastx; i < n; ++i)
   {
      for (int j = 0; j < n; ++j)
      {
         // check
         if (i == lastx and j <= lasty)continue;
         if (check1(i, j)) {
            // move
            board[i][j] = 1;
            rec(level + 1, i, j);
            board[i][j] = 0;
         }
      }
   }
}

void solve()
{
   cin >> n >> k;
   ans = 0;
   rec(0, 0, -1);
   cout << ans << endl;
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