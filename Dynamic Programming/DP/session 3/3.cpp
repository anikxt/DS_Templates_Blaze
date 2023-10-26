#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// LIS - NlogN

int lis(vector<int> arr) {
	vector<int> temp;
	for (auto v : arr) {
		if (temp.empty() or temp.back() <= v) {
			temp.push_back(v);
		} else {
			auto it = lower_bound(temp.begin(), temp.end(), v);
			*it = v;
		}
	}
	return temp.size();
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
