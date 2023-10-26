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

// Application Form 3 - Intraset Matching

/*
Problem Statement:
There are 2*N Chess players and N Boards in a chess tournament.
The rating of the Chess Player is given by the array A.
Every player can play only with one player.
There is a N board pairing to be done, and if you match
Player i and Player j in the board K, then the Happiness Score
increases by K*abs(A[i]-A[j])*gcd(A[i],A[j]).
Find the Maximum Happiness score you can make by designing a ideal pairing.

Constraints:
N <= 10
A[i] <= 10^6
*/

/*
Time Complexity:
#State = O(2^(2N))
#Transitions = O(N^2)
Overall = O((N^2)*(2^(2N)))
*/

#define int long long
const int N = 10;
int n;
int arr[2 * N];
// state space reduction =>(#onbit(mask)/2) + 1 = board
int dp[1 << (2 * N)];

// level -> board
int rec(int mask) {
    int level = __builtin_popcount(mask);
    level /= 2;

    if (level == n)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    int ans = 0;
    for (int i = 0; i < 2 * n; ++i)
    {
        for (int j = i + 1; j < 2 * n; ++j)
        {
            if (mask & ((1 << i) | (1 << j)))
                continue;

            ans = max(ans, rec(mask | (1 << i) | (1 << j)) + ((level + 1) * (abs(arr[i] - arr[j])) * __gcd(arr[i], arr[j])));
        }
    }

    return dp[mask] = ans;
}

// when the answer is not dependent on board i.e. abs(A[i]-A[j])*gcd(A[i],A[j])
/*
Take the first 0 in the mask and try to match it with every other 0.
*/
int dp2[1 << (2 * N)];
// Time Complexity =>  O(N*2^(2N))
int rec2(int mask) {
    int level = __builtin_popcount(mask);
    level /= 2;

    if (level == n)
        return 0;

    if (dp2[mask] != -1)
        return dp2[mask];

    int ans = 0;
    // find the first 0 (unmatched person)
    int i = log2(mask ^ (mask | (mask + 1)));
    for (int j = i + 1; j < 2 * n; ++j)
    {
        if (mask & ((1 << i) | (1 << j)))
            continue;

        ans = max(ans, rec(mask | (1 << i) | (1 << j)) + ((abs(arr[i] - arr[j])) * __gcd(arr[i], arr[j])));
    }

    return dp2[mask] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < 2 * n; ++i)
    {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << rec(0) << endl;
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
