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

// Application Form 5 - Profile DP

/*
Problem Statement:
Given a Rectangular Board of NxM board,
Find the number of ways of Tiling the Board with Dominos.

Constraints:
1 <= N, M <= 12
*/

/*
Time Complexity:
#State = O(N*M*(2^M))
#Transitions = O(1)
Overall = O(N*M*(2^M))
*/

#define int long long
const int N = 15;
int n, m;
int dp[N][N][1 << N];

void get_next_point(int i, int j, int *ansi, int *ansj) {
    if (j == m - 1) {
        *ansi = i + 1;
        *ansj = 0;
    } else {
        *ansi = i;
        *ansj = j + 1;
    }
}

int rec(int i, int j, int mask) {
    if (i == n) {
        return (mask == (1 << m) - 1);
    }

    if (dp[i][j][mask] != -1)
        return dp[i][j][mask];

    int ans = 0;
    int nexti, nextj;
    get_next_point(i, j, &nexti, &nextj);

    // Leave
    if (i == 0 or (mask & 1)) {
        ans += rec(nexti, nextj, (mask >> 1));
    }

    // Config-2 (V)
    if (i > 0 and (!(mask & 1))) {
        int nMask = (mask >> 1);
        nMask |= (1 << (m - 1));
        ans += rec(nexti, nextj, nMask);
    }

    // Config-1 (H)
    if (j != 0 and !((mask >> (m - 1)) & 1)) {
        if (i == 0 or (i > 0 and (mask & 1))) {
            int nMask = (mask >> 1);
            nMask |= (1 << (m - 1));
            nMask |= (1 << (m - 2));
            ans += rec(nexti, nextj, nMask);
        }
    }

    return dp[i][j][mask] = ans;
}

void solve()
{
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0) << endl;
    return;
}
#undef int

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