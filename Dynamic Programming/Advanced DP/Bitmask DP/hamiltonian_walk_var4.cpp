#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Application Form 2 - Hamiltonian Walk - Count Simple Paths

/*
Problem Statement:
A City is modelled using a Graph with N nodes and M edges.
The nodes are numbered from 1 to N.
Find the number of Simple Paths.

Constraints:
N <= 20
*/

/*
Time Complexity:
Overall: O((N+M)*2^N) ~ (N^2*2^N) in general,
because number of edges can be of N^2.
*/

#define int long long
int n, m, start;
vector<vector<int>> g;
int dp[25][(1 << 20)];

int rec(int level, int mask) {
	/*
	whenever n-th bit gets set, you just stop.
	this means, you never consider masks with the n-th bit set.
	*/
	if (dp[level][mask] != -1)
		return dp[level][mask];

	int ans = ((__builtin_popcountll(mask) >= 2 ? 1 : 0));
	for (auto v : g[level]) {
		/*
		most crucial : prevent overcounting,
		v < start has already been covered
		when the prev_start was less than current_start.
		*/

		/*
		yeh isliye rakhe hai, ki joh aaage cycle baane uss mein saara node
		current se baada hi rahe pehle waala cycle naa add ho, haar baar.
		*/
		if (v < start)
			continue;

		/*
		shifting v to v-1 position in bit
		so that it would remain between 0 to n-1.
		this is just an implementation level detail.
		*/
		if (mask & (1 << (v - 1)))
			continue;

		ans += rec(v, mask | (1 << (v - 1)));
	}

	return dp[level][mask] = ans;
}

void solve()
{
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		start = i;
		memset(dp, -1, sizeof(dp));
		sum += rec(i, (1 << (i - 1)));
	}

	/*
	so you are overcounting the reverses as well,
	but that's easy, just divide again by 2.
	the first division by n ensures all cycle rotations
	collapse to start with the same value,
	(let's say, the smaller value of the rotation).
	the next division by 2 just ensures we ignore the reflexes.

	intuitively, 1abc has only one reverse, 1cba, so

	1234=1432
	1243=1342
	1324=1423
	*/
	// sum /= n;

	/*
	yeh isliye rakhe hai, kyuki joh cycle hai clocwise aur anticlowise,
	dono baar count ho jaa raha hai.
	*/
	sum /= 2;

	cout << sum << endl;
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

