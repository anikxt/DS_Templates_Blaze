#include <bits/stdc++.h>
using namespace std;

vector<int> g[100100];
int dep[100100];
int par[100100];

void dfs(int node, int parent, int depth) {
    dep[node] = depth;
    par[node] = parent;
    for (auto v : g[node]) {
        if (v != parent) {
            dfs(v, node, depth + 1);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    int maxch = 1;
    for (int j = 2; j <= n; j++) {
        if (dep[j] > dep[maxch]) {
            maxch = j;
        }
    }
    dfs(maxch, 0, 0);
    int maxch = 1;
    for (int j = 2; j <= n; j++) {
        if (dep[j] > dep[maxch]) {
            maxch = j;
        }
    }
    cout << dep[maxch] << endl;
}