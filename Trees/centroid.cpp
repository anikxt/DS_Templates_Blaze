#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

const int N = 200200;
int n;
vector<vector<int>> g;
vector<int> par, subtreeSz;

void dfs(int node, int parent) {
    par[node] = parent;
    subtreeSz[node] = 1;
    for (auto v : g[node]) {
        if (v != parent) {
            dfs(v, node);
            subtreeSz[node] += subtreeSz[v];
        }
    }
}

void solve()
{
    cin >> n;
    g.resize(n + 1), par.resize(n + 1), subtreeSz.assign(n + 1, 0);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);

    int node = 1;
    while (true) {
        bool flag = false;
        for (auto v : g[node]) {
            if (v != par[node]) {
                if (subtreeSz[v] > (n / 2)) {
                    flag = true;
                    node = v;
                    break;
                }
            }
        }
        if (flag == false) {
            cout << node << endl;
            return;
        }
    }
    return;
}

int main()
{
    blaze;
    // int _t; cin >> _t; while (_t--)
    solve();
    return 0;
}