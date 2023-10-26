#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*

In-Out DP Tree:
indp(node) = Summ. (indp(child) + subtreeSz(child))
outdp(node) = Summ. (outdp(parent) + indp(parent) - (indp(node) + subtreeSz(node)) + (N - subtreeSz(node)))

ans(node) = indp(node) + outdp(node)

      root  (outdp(root) = 0) (we build from top to bottom)
      / \
     /   \
     B    C
    / \
   /   \
 leaf leaf (indp(leaf) = 0) (we build from bottom to top)

*/

/*
Problem Statement:
ans(i) = Summ. (x = 1 to N) (dist(i, x)), for all (i = 1 to N)
basically, ans(1), ans(2), ..., ans(n)
*/

int n;
vector<int> g[100100];
int subtreeSz[100100];
int indp[100100];
int outdp[100100];

void indfs(int node, int parent) {
    indp[node] = 0;
    subtreeSz[node] = 1;

    for (auto v : g[node]) {
        if (v != parent) {
            indfs(v, node);
            subtreeSz[node] += subtreeSz[v];
            indp[node] += indp[v] + subtreeSz[v];
        }
    }
}

void outdfs(int node, int parent) {
    if (node == 1) {
        outdp[node] = 0;
    } else {
        outdp[node] = outdp[parent] + indp[parent] - (indp[node] + subtreeSz[node]) + (n - subtreeSz[node]);
    }

    for (auto v : g[node]) {
        if (v != parent) {
            outdfs(v, node);
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    indfs(1, 0);
    outdfs(1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cout << indp[i] + outdp[i] << " ";
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
