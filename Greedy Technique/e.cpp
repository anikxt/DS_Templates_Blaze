#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// maximum sum of the array after performing k negations of elements.

#define int long long
int maximum_sum(vector<int> &arr, int k) {
	int n = arr.size(), ans = 0;
	priority_queue<int, vector<int> greater<int>> pq;
	for (int i = 0; i < n; ++i)
	{
		pq.push(arr[i]);
	}
	for (int i = 0; i < k; ++i)
	{
		int p = pq.top();
		pq.pop();
		if (p == 0)
			break;
		p = -p;
		q.push(p);
	}
	while (!q.empty()) {
		ans += pq.top();
		pq.pop();
	}
	return ans;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int ans = maximum_sum(arr, k);
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