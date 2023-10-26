#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// cycle check + print using parent

int n, m;
vector<vector<int>> g;
vector<int> col;
vector<int> parent;
bool is_cycle = 0;
vector<int> any_cycle;

void dfs(int node, int par) { // O(N + M)
    parent[node] = par;
    col[node] = 2;
    for (auto v : g[node]) {
        // add for undirected
        // if (v == parent[node])continue;
        if (col[v] == 1) {
            // node - v is a forward edge
            dfs(v, node);
        } else if (col[v] == 2) {
            // node - v is a back edge
            // We found a cycle !!
            cout << "Hit: " << node << endl;
            if (is_cycle == 0) {
                int temp = node;
                while (temp != v) {
                    any_cycle.push_back(temp);
                    temp = parent[temp];
                }
                any_cycle.push_back(temp);
                reverse(any_cycle.begin(), any_cycle.end());
            }
            is_cycle = 1;

        } else if (col[v] == 3) {
            // node - v is a cross edge
            // unimportant
        }
    }
    col[node] = 3;
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    col.assign(n + 1, 1);
    parent.assign(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (col[i] == 1) {
            dfs(i, 0);
        }
    }

    for (auto v : any_cycle) {
        cout << v << " ";
    }
    cout << endl;
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