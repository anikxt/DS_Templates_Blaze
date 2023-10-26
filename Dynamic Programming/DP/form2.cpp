#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// maximum sum subarray
// dp(level) -> max. sum ending at level

#define int long long
int n;
int arr[100100];

bool done[100100];
int dp[100100];
int rec(int level) {
	// pruning
	if (level < 0) {
		return 0;
	}

	// cache check
	if (done[level]) {
		return dp[level];
	}

	// compute
	int ans = max(rec(level - 1) + arr[level], arr[level]);

	// save and return
	done[level] = 1;
	return dp[level] = ans;
}

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int ans = rec(0);
	for (int i = 1; i < n; ++i)
	{
		ans = max(ans, rec(i));
	}

	cout << ans << endl;
	return;
}
#undef int

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
