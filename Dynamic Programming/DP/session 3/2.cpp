#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
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
#define clr(x, y) memset(x, y, sizeof(x))
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

// LIS - N^2

int n;
int arr[10010];
int dp[10010];

int rec(int level)
{
	// best LIS ending at level.
	// pruning
	if (level < 0)
		return 0;

	// base case

	// cache check
	if (dp[level] != -1)
		return dp[level];

	// compute
	int ans = 1;
	for (int prev_taken = 0; prev_taken < level; prev_taken++)
	{
		if (arr[prev_taken] < arr[level])
		{
			ans = max(ans, 1 + rec(prev_taken));
		}
	}

	// save and return
	return dp[level] = ans;
}

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));
	int best = 0;
	for (int i = 0; i < n; ++i)
	{
		best = max(best, rec(i));
		cout << best << " ";
	}

	return;
}

int main()
{
	blaze;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
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