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

// LCS

int n, m;
string s1, s2;

int dp[2021][2021];

int rec(int l1, int l2) { // s1[l1...n-1], s2[l2...m-1]
	// pruning/base case
	if (l1 == n or l2 == m) {
		return 0;
	}

	// cache check
	if (dp[l1][l2] != -1) {
		return dp[l1][l2];
	}

	// compute/transition
	int ans = 0;
	if (s1[l1] == s2[l2]) {
		ans = 1 + rec(l1 + 1, l2 + 1);
	} else {
		ans = max(rec(l1, l2 + 1), rec(l1 + 1, l2));
	}

	// save and return
	return dp[l1][l2] = ans;
}

void solve()
{
	cin >> s1 >> s2;
	n = s1.size();
	m = s2.size();
	memset(dp, -1, sizeof(dp));
	cout << rec(0, 0) << endl;
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