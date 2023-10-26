#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*

N <- A : [1, 5, 3, 2, 7]
M <- B: [5, 9, 3, 7, 1]

given - all elements are distinct

(N, M <= 1e5)

find LCS

*/

int lis(vector<int> &arr) {
	vector<int> temp;
	for (auto v : arr) {
		if (temp.empty() or temp.back() < v) {
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
	vector<int> A, B, temp;
	map<int, int> mp;
	for (int i = 0; i < A.size(); ++i)
	{
		mp[A[i]] = i;
	}
	for (auto v : B) {
		if (mp.find(v) != mp.end()) {
			temp.push_back(mp[v]);
		}
	}

	cout << lis(temp) << endl;
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
