#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

//  min_cost_to_join(rope);

#define int long long
int  min_cost_to_join(vector<int, int> &rope) {
	int n = rope.size();
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; ++i)
	{
		pq.push(rope[i]);
	}
	int cost = 0;
	while (!pq.empty()) {
		int x = pq.top();
		pq.pop();

		if (q.empty())
			break;

		int y = pq.top();
		pq.pop();
		cost += (x + y);
		pq.push(x + y);
	}
	return cost;
}

void solve()
{
	int n;
	cin >> n;
	vector<int, int> rope(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> rope[i];
	}
	int ans = min_cost_to_join(rope);
	cout << ans << endl;
	return;
}

signed main()
{
	blaze;
	int _t = 1;
	cin >> _t;
	while (_t--) {
		solve();
	}
	return 0;
}