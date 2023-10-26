#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*

In-Out DP Tree:
indp(node) = Summ. (indp(child) + subtreeSz(child))
outdp(node) = Summ. (outdp(parent) + indp(parent) - (indp(node) - subtreeSz(node)) + (N - subtreeSz(node)))

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
ans(i) = height if you root at i, for all (i = 1 to N)
basically, ans(1), ans(2), ..., ans(n)
*/

int n;
vector<int> g[100100];

int indp[100100];
int outdp[100100];

int ans[100100];

void indfs(int node, int parent) {
    // set it value as if its a leaf
    indp[node] = 0;

    for (auto ch : g[node]) {
        if (ch != parent) {
            indfs(ch, node);
            indp[node] = max(indp[node], indp[ch] + 1);
        }
    }
}

void outdfs(int node, int parent, int outVal) {
    outdp[node] = outVal;

    int max1 = -1, max2 = -1;
    for (auto ch : g[node]) {
        if (ch != parent) {
            if (indp[ch] > max1) {
                max2 = max1;
                max1 = indp[ch];
            } else if (indp[ch] > max2) {
                max2 = indp[ch];
            }
        }
    }

    for (auto ch : g[node]) {
        if (ch != parent) {
            if (indp[ch] == max1) {
                outdfs(ch, node, max(max2 + 2, outdp[node] + 1));
            } else {
                outdfs(ch, node, max(max1 + 2, outdp[node] + 1));
            }
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
    outdfs(1, 0, 0);
    for (int i = 1; i <= n; ++i)
    {
        ans[i] = max(indp[i], outdp[i]);
        cout << ans[i] << " ";
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
