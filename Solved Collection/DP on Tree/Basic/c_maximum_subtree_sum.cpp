#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
P1122 Maximum subtree sum

finding connected component with largest sum
*/

int n;
vector<int> a;
vector<vector<int>> g;
int dp[20000];

void indfs(int node, int parent) {
    dp[node] = a[node];

    for (auto v : g[node]) {
        if (v != parent) {
            indfs(v, node);
            dp[node] += max(dp[v], 0);
        }
    }
}

void solve() {
    cin >> n;

    a.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    g.resize(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    indfs(1, 0);
    int ans = INT_MIN;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
    return;
}

int main()
{
    blaze;
    // int _t; cin >> _t; while (_t--)
    solve();
    return 0;
}