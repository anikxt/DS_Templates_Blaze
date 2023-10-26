#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
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
	int _t = 1;
	cin >> _t;
	while (_t--) {
		solve();
	}
	return 0;
}
