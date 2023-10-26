#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Game DP - substraction game
int n;
vector<int> moves = {1, 3, 4};

int dp[100100];
int rec(int x) {
	if (x == 0)
		return 0;

	if (dp[x] != -1) {
		return dp[x];
	}

	int ans = 0;
	for (auto v : moves) {
		if (v <= x and rec(x - v) == 0) {
			ans = 1;
			break;
		}
	}

	return dp[x] = ans;
}

void solve()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	// cout << rec(n) << endl;
	for (int i = 0; i <= 20; ++i)
	{
		cout << i << " " << rec(i) << endl;
	}
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
