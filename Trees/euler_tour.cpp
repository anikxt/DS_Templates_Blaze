#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
Properties of Euler Tour:
1. len = 2 * size(subtree)
2. child range in parent range
3. cuts only ancestors

*/

// subtree sum with updates
// solving with 2*n version (there's a separate node for start and end point)

int n;
vector<int> g[100100];
int val[100100];

int timer = 0;
int in[100100];
int out[100100];

void dfs(int nn, int pp) {
	timer++;
	in[nn] = timer;

	for (auto v : g[nn]) {
		if (v != pp) {
			dfs(v, nn);
		}
	}
	timer++;
	out[nn] = timer;
}

// segment tree
int tt[4 * 2 * 100100];

void update(int id, int l, int r, int x, int lasty ) {
	if (x < l or x > r)
		return;

	if (l == r) {
		t[id] = y;
		return;
	}

	int mid = (l + r) / 2;
	update(id << 1, l, mid, x, y);
	update(id << 1 | 1, mid + 1, r, x, y);
	t[id] = t[id << 1] + t[id << 1 | 1];
}

void query(int id, int l, int r, int lq, int rq) {
	if (l > rq or lq > r)return 0;
	if (lq <= l and r <= rq) {
		return t[id];
	}

	int mid = (l + r) / 2;
	return query(id << 1, l, mid, lq, rq) + query(id << 1 | 1, mid + 1, r, lq, rq);
}

int main() {
	blaze;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);

	int q;
	cin >> q;
	while (q--) {
		char ch;
		cin >> ch;
		if (ch == '1') {
			// update
			int x, y;
			cin >> x >> y;
			update(1, 1, 2 * n, in[x], y);
		} else {
			//query
			int x;
			cin >> x;
			query(1, 1, 2 * n, in[x], out[x]);
		}
	}
	return 0;
}