#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
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
	int _t = 1;
	cin >> _t;
	while (_t--) {
		solve();
	}
	return 0;
}
