#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Generating Permutations

int n;
map<int, int> mp;
vector<vector<int>> all_sol;
vector<int> cur_perm;

void rec(int level) {
	if (level == n) {
		all_sol.push_back(cur_perm);
		return;
	}

	for (auto v : mp) {
		if (v.second != 0) {
			mp[v.first]--;
			cur_perm.push_back(v.first);
			rec(level + 1);
			cur_perm.pop_back();
			mp[v.first]++;
		}
	}
}

void solve()
{
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		mp[arr[i]]++;
	}
	rec(0);
	return;
}

int main()
{
	blaze;
	int _t = 1;
	// cin >> _t;
	while (_t--) {
		solve();
	}
	return 0;
}