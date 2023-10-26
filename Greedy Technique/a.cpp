#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Job Sequencing Problem

#define int long long
bool cmp(pair<int, int> &a, pair<int, int>&b) {
	return a.second < b.second;
}

int maxjobs(vector<pair<int, int>> &v) {
	int n = v.size(), cnt = 0;
	int prev_end = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		if (v[i].first >= prev_end) {
			cnt++;
			prev_end = v[i].second;
		}
	}
	return cnt;
}

void solve()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i)
	{
		int start, end;
		cin >> start >> end;
		v[i] = {start, end};
	}
	sort(v.begin(), v.end(), cmp);
	int ans = maxjobs(v);
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