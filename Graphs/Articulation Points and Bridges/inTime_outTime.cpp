#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

#define MAXN 100100
vector<int> g[MAXN];
int inTime[MAXN];
int outTime[MAXN];
int timer = 0;

void dfs(int node, int par) {
    inTime[node] = ++timer;
    for (auto v : g[node]) {
        if (!inTime[v]) {
            dfs(v, node);
        }
    }
    outTime[node] = ++timer;
}

bool is_U_Ancestor_of_V(int u, int v) {
    if (inTime[u] <= inTime[v] and outTime[u] >= outTime[v]) {
        return 1;
    } else return 0;
}

void solve()
{

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