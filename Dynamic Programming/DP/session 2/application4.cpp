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

Wythoff's game is a two-player mathematical subtraction game,
played with two piles of counters.
Players take turns removing counters from one or both piles;
when removing counters from both piles,
the numbers of counters removed from each pile must be equal.
The game ends when one player removes the last counter or counters, thus winning.

*/

int dp[1010][1010];
int rec(int x, int y) {
	if (x == 0 and y == 0) {
		return 0;
	}

	if (dp[x][y] != -1) {
		return dp[x][y];
	}

	int win = 0;
	for (int i = 1; i <= x; ++i)
	{
		if (rec(x - i, y) == 0) {
			win = 1;
		}
	}

	for (int i = 1; i <= y; ++i)
	{
		if (rec(x, y - i) == 0) {
			win = 1;
		}
	}

	for (int i = 1; i <= min(x, y); ++i)
	{
		if (rec(x - i, y) == 0) {
			win = 1;
		}
	}

	return dp[x][y] = win;
}

void solve()
{

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