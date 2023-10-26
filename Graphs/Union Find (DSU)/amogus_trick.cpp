#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Amogus Trick
// https://codeforces.com/blog/entry/106407
// This code is for the problem -> https://codeforces.com/contest/1594/problem/D
// example problem for solving -> https://www.spoj.com/problems/CHAIN/


struct DSU {
    vector<int> pt, sz, wt;
    DSU(int n) : pt(n * 2 + 1), sz(n * 2 + 1, 1), wt(n * 2 + 1) {
        for (int i = 1; i <= n; ++i) {
            pt[i] = i;
            pt[i + n] = i + n;
            wt[i + n] = 1;
        }
    }
    int find(int i) {
        return i == pt[i] ? i : pt[i] = find(pt[i]);
    }
    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (sz[i] < sz[j])
                swap(i, j);
            pt[j] = i;
            sz[i] += sz[j];
            wt[i] += wt[j];
        }
    }
    bool connected(int i, int j) {
        return find(i) == find(j);
    }
};

void solve()
{
    int n, q, x, y, ans = 0;
    string s;
    cin >> n >> q;
    DSU dsu(n);
    while (q--) {
        cin >> x >> y >> s;
        if (s[0] == 'c') {
            dsu.unite(x, y);
            dsu.unite(x + n, y + n);
        }
        else {
            dsu.unite(x, y + n);
            dsu.unite(x + n, y);
        }
    }
    for (int i = 1; i <= n; ++i)
        if (dsu.connected(i, i + n)) {
            cout << "-1\n";
            return;
        }
    for (int i = 1; i <= n; ++i)
        if (dsu.find(i) == i) // Each component is only considered once on its leader
            ans += max(dsu.wt[dsu.find(i)], dsu.wt[dsu.find(i + n)]);
    cout << ans << "\n";
}

int main()
{
    blaze;
    int _t;
    cin >> _t;
    while (_t--) {
        solve();
    }
    return 0;
}