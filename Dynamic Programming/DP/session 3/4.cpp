#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// LNDS - NlogN

int lis(vector<int> &arr) {
	vector<int> temp;
	int len;
	for (auto v : arr) {
		if (temp.empty() or temp.back() <= v) {
			temp.push_back(v);
		} else {
			auto it = upper_bound(temp.begin(), temp.end(), v);
			*it = v;
		}

		for (auto it : temp) {
		}
		cout << endl;
	}
	return temp.size();
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	cout << lis(a) << endl;
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
