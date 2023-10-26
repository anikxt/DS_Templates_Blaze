#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// classical knapsack

int n, W;
int p[1010];
int w[1010];

int dp[1010][2020];
int rec(int level, int taken) {
	// pruning
	if (taken > W)
		return -1e9;

	// base case
	if (level == n) {
		return 0;
	}

	// cache check
	if (dp[level][taken] != -1) {
		return dp[level][taken];
	}

	// compute/transition
	int ans = max(p[level] + rec(level + 1, taken + w[level]), // take the item
	              0 + rec(level + 1, taken)); // don't take the item

	// save and return
	return dp[level][taken] = ans;
}

void solve()
{
	cin >> n >> W;
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i] >> w[i];
	}

	memset(dp, -1, sizeof(dp));
	cout << rec(0, 0) << endl;
	return;
}

int main()
{
	blaze;
	int _t = 1;
	cin >> _t;
	while (_t--) {
		solve();
	}
	return 0;
}
