#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// components connectivity

int n, m;
vector<vector<int>> g;
vector<int> vis;

void dfs(int node, int comp) {
    vis[node] = comp;
    for (auto v : g[node]) {
        if (!vis[v]) {
            dfs(v, comp);
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    vector<pii> edgelist;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        edgelist.push_back({a, b});
    }

    int num_comp = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i]) {
            num_comp++;
            dfs(i, num_comp);
        }
    }

    vector<int> num_of_edge(num_comp + 1);
    for (auto v : edgelist) {
        num_of_edge[vis[v.first]]++;
    }
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