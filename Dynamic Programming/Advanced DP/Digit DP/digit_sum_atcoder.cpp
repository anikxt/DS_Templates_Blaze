#include <bits/stdc++.h>
typedef long long int ll;
#define gc getchar_unlocked
#define fab(i, a, b) for (int i = a; i <= b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define pr(v) for(auto &z: v) cout << z << ' '; cout << '\n'
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

// https://atcoder.jp/contests/dp/tasks/dp_s

#define int long long
string L, R;
int D, len;

int dp[10010][2][2][100]; // number of digits, two tights, sum mod D

int rec(int level, int tlo, int thi, int sumD) {
    if (level == len) {
        if (sumD == 0)
            return 1;
        return 0;
    }

    if (dp[level][tlo][thi][sumD] != -1)
        return dp[level][tlo][thi][sumD];

    int ans = 0;
    int lo = 0;
    if (tlo == 1) {
        lo = L[level] - '0';
    }

    int hi = 9;
    if (thi == 1) {
        hi = R[level] - '0';
    }

    for (int i = lo; i <= hi; ++i)
    {
        int ntlo = tlo;
        if (i != L[level] - '0') {
            ntlo = 0;
        }

        int nthi = thi;
        if (i != R[level] - '0') {
            nthi = 0;
        }

        (ans += rec(level + 1, ntlo, nthi, (sumD + i) % D)) %= MOD;
    }

    return dp[level][tlo][thi][sumD] = ans;
}

void solve()
{
    L = "1";
    cin >> R >> D;
    int cnt = R.size() - L.size(); // checking how much padding is required
    string temp = "";
    while (cnt--) {
        temp += '0';
    }
    L = temp + L;
    len = R.size();
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1, 0) << endl;
    return;
}
#undef int

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