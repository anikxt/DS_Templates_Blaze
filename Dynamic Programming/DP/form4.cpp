#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// LR DP

// +arr[l] - dp(l+1,r) => +arr[l] - (P2 - P1)
// (+arr[l] + P1) - (P2)
//    P1total     - P2total

int n;
int arr[2021];

bool done[2021][2021];
int dp[2021][2021];
int rec(int l, int r) {
	// base case
	if (l == r) {
		return arr[l];
	}

	if (done[l][r]) {
		return dp[l][r];
	}

	int ans = max(arr[l] - rec(l + 1, r), arr[r] - rec(l, r - 1));

	done[l][r] = 1;
	return dp[l][r] = ans;
}

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			done[i][j] = 0;
		}
	}

	cout << rec(0, n - 1) << endl;
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
