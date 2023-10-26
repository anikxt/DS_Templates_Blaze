#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// for all x: find max(abs(val[x] - val[y])), where y is the ancestor of x

int ans[100100];
int val[100100];
int root;

void dfs(int node, int par, int maxVal, int minVal) {
    ans[node] = max(abs(maxVal - val[node]), abs(minVal - val[node]));
    for (auto v : g[node]) {
        if (v != par) {
            dfs(v, node, max(maxVal, val[node]), min(minVal, val[node]));
        }
    }
}

void solve()
{
    dfs(root, 0, - 1e9, 1e9);
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