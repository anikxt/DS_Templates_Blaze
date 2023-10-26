#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
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
	int _t = 1;
	cin >> _t;
	while (_t--) {
		solve();
	}
	return 0;
}
