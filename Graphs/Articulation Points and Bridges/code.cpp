#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

#define MAXN 100100
vector<int> g[MAXN];
int inTime[MAXN], loTime[MAXN];
int timer = 0;

int numSplit[MAXN]; // if this is deleted how many new components will be formed

int dfs(int node, int par) {
    timer++;
    inTime[node] = loTime[node] = timer;
    bool isArti = false;
    int child = 0;

    numSplit[node] = 1;
    for (auto x : g[node]) {
        if (x == par)continue;
        if (!inTime[x]) { // node - x forward edge
            child++;
            dfs(x, node);
            loTime[node] = min(loTime[node], loTime[v]);
            if (loTime[x] >= inTime[node]) {
                isArti = true;
                numSplit[node]++;
                // x will be a new component
            }

            if (loTime[v] > inTime[node]) {
                // node - x is a bridge
                // pr(node, x);
            }
        } else { // node - x is a back edge
            loTime[node] = min(loTime[node], inTime[x]);
        }
    }

    if (par == 0) {
        numSplit[node] = child;
    }

    if ((par == 0 and child >= 2) or (par != 0 and isArti)) {
        // this node is an articulation point
        // pr("Art", node);
    }
}

void solve()
{   int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int comp = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!inTime[i]) {
            comp++;
            dfs(i, 0);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (g[i].size() == 0) {
            cout << comp - 1 << " ";
        } else {
            cout << comp - 1 + numSplit[i] << " ";
        }
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