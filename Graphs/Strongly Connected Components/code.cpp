#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Kosaraju's Algorithm

int n, m;
vector<int> g[100100];
vector<int> grev[100100];

vector<int> vis(100100, 0);
vector<int> tout_order;

void dfs1(int x) {
    vis[x] = 1;
    for (auto v : g[x]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }
    tout_order.push_back(x);
}

int cur_scc = 0;
int scc_num[100100];

void dfs2(int x) {
    scc_num[x] = cur_scc;
    vis[x] = 1;
    for (auto v : grev[x]) {
        if (!vis[v]) {
            dfs2(v);
        }
    }
}

vector<vector<int>> condensed_graph;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        grev[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }

    reverse(tout_order.begin(), tout_order.end());
    vis.assign(n + 1, 0);

    for (auto x : tout_order) {
        if (!vis[x]) {
            cur_scc++;
            dfs2(x);
        }
    }

    condensed_graph.resize(cur_scc + 1);

    vector<int> indeg(cur_scc + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (auto v : g[i]) {
            if (scc_num[i] != scc_num[v]) {
                indeg[scc_num[v]]++;
                condensed_graph[scc_num[i]].push_back(scc_num[v]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= cur_scc; i++) {
        if (indeg[i] == 0)ans++;
    }

    cout << ans << endl;
}

int main() {
    blaze;
    int _t = 1;
    // cin>>_t;
    while (_t--) {
        solve();
    }
    return 0;
}