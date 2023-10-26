#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int n, m;
vector<vector<int>> g;
vector<int> vis;

vector<int> topo;

void dfs(int node) {
    vis[node] = 1;
    for (auto v : g[node]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    topo.push_back(node);
}

// int dp[100100];
// int rec(int node) { // longest path starting at node
//     if (dp != -1)return dp[node];
//     int ans = 1;
//     for (auto v : g[node]) {
//         ans = max(ans, 1 + rec(v));
//     }
//     return dp[node] = ans;
// }

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    // memset(dp, -1, sizeof(dp));
    // int ans = 0;
    // for (int i = 1; i <= n; ++i)
    // {
    //     ans = max(ans, rec(i));
    // }
    // cout << ans << endl;

    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i]) {
            dfs(i);
        }
    }

    // reverse(topo.begin(), topo.end());
    // for (auto v : topo) {
    //     cout << v << " ";
    // }

    int final = 0;
    for (auto node : topo) {
        int ans = 1;
        for (auto v : g[node]) {
            ans = max(ans, 1 + dp[v]);
        }
        dp[node] = ans;
        final = max(final, dp[node]);
    }
    cout << final << endl;

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