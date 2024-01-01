#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
P1131 [ZJOI2007] Temporal synchronization

The meaning of the question is to make the distance
from the leaf node to the root node the same with the least cost.
*/

#define int long long
int n, root;
vector<vector<pair<int, int>>> edge;

int dp[1000100];
int ans = 0;

void indfs(int node, int parent) {
    for (auto z : edge[node]) {
        int v = z.first, w = z.second;
        if (v != parent) {
            indfs(v, node);
            dp[node] = max(dp[node], dp[v] + w);
        }
    }

    for (auto z : edge[node]) {
        int v = z.first, w = z.second;
        if (v != parent) {
            ans += dp[node] - dp[v] - w;
        }
    }
}

void solve() {
    cin >> n >> root;

    edge.resize(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    indfs(root, 0);
    cout << ans << endl;
    return;
}

signed main()
{
    blaze;
    // int _t; cin >> _t; while (_t--)
    solve();
    return 0;
}