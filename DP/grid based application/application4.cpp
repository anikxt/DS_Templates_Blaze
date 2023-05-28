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

// Cherry Pickup Problem

int n, m;
int arr[50][50];
int dp[50][50][50];

bool check(int x, int y) {
	if (x >= n or y >= m)
		return 0;
	return 1;
}

int rec(int r1, int c1, int r2) { // r1 + c1 = r2 + c2
	int c2 = r1 + c1 - r2; // state space reduction
	if ((!check(r1, c1)) or (!check(r2, c2))) {
		return -1e9;
	}

	// base case
	if (r1 == n - 1 and c1 == m - 1 and r2 == n - 1 and c2 == n - 1) {
		return arr[r1][c1];
	}

	// cache check
	if (dp[r1][c1][r2] != -2e9) {
		return dp[r1][c1][r2];
	}

	int ans = ((r1 == r2 and c1 == c2) ? arr[r1][c1] : arr[r1][c1] + arr[r2][c2]);
	ans = ans + max({rec(r1 + 1, c1, r2 + 1), rec(r1, c1 + 1, r2 + 1), rec(r1 + 1, c1, r2), rec(r1, c1 + 1, r2)});
	return dp[r1][c1][r2] = ans;
}

void solve()
{
	// rec(0, 0, 0, 0)
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