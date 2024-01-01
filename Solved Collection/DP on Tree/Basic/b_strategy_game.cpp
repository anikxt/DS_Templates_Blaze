#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
P2016 Strategy Game

Minimum weight covering set problem

Place some soldiers on the nodes of a tree so that
all edges have at least one endpoint with soldiers,
and find the minimum number of soldiers.
*/

int n;
vector<vector<int>> g;
int dp[2000][2];

void indfs(int node, int parent) {
    dp[node][0] = 0;
    dp[node][1] = 1;

    for (auto v : g[node]) {
        if (v != parent) {
            indfs(v, node);
            dp[node][0] += dp[v][1];
            dp[node][1] += min(dp[v][0], dp[v][1]);
        }
    }
}

void solve() {
    cin >> n;

    g.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int x, k;
        cin >> x >> k;
        x++;
        for (int i = 0; i < k; ++i)
        {
            int y;
            cin >> y;
            y++;
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }

    indfs(1, 0);
    cout << min(dp[1][0], dp[1][1]) << endl;
    return;
}

int main()
{
    blaze;
    // int _t; cin >> _t; while (_t--)
    solve();
    return 0;
}