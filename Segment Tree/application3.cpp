#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
Design a DS

N arr

Query:
1 x v -> update arr[x] = v
2 l r -> find max sum subarray [l, r]
*/

#define int long long
const int N = 200200;
int n, q;
int arr[N];

struct node {
	int lsum;
	int rsum;
	int totSum;
	int msum;
	node(int l = -1e6, int r = -1e6, int t = -1e6, int m = -1e6) {
		lsum = l;
		rsum = r;
		totSum = t;
		msum = m;
	}
};

node merge(node a, node b) {
	node c;
	c.lsum = max(a.lsum, a.totSum + b.lsum);
	c.rsum = max(b.rsum, a.rsum + b.totSum);
	c.totSum = a.totSum + b.totSum;
	c.msum = max({a.msum, b.msum, a.rsum + b.lsum});
	return c;
}

node t[4 * N];

void build(int index, int l, int r) {
	if (l == r) {
		int x = max(arr[l], 0LL);
		t[index] = node(arr[l], arr[l], x, arr[l]);
		return;
	}

	int mid = (l + r) / 2;
	build(index * 2, l, mid);
	build(index * 2 + 1, mid + 1, r);
	t[index] = merge(t[2 * index], t[2 * index + 1]);
}

void update(int index, int l, int r, int pos, int val) {
	if (pos < l or pos > r)
		return;

	if (l == r) {
		int x = max(val, 0LL);
		t[index] = node(val, val, x, val);
		return;
	}

	int mid = (l + r) / 2;
	update(index * 2, l, mid, pos, val);
	update(index * 2 + 1, mid + 1, r, pos, val);
	t[index] = merge(t[2 * index], t[2 * index + 1]);
}

node query(int index, int l, int r, int lq, int rq) {
	if (l > rq or lq > r)
		return 0;

	if (lq <= l and r <= rq) {
		// lq <= l <= r <= rq
		return t[index];
	}

	int mid = (l + r) / 2;
	return merge(query(index * 2, l, mid, lq, rq), query(index * 2 + 1, mid + 1, r, lq, rq));
}

void solve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}

	build(1, 1, n);

	while (q--)
	{
		int ch;
		cin >> ch;
		if (ch == 1) {
			int pos, val;
			cin >> pos >> val;
			update(1, 1, n , pos, val);
		} else {
			int l, r;
			cin >> l >> r;
			node x = query(1, 1, n, l, r);
			cout << x.msum << endl;
		}
	}
	return;
}
#undef int

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