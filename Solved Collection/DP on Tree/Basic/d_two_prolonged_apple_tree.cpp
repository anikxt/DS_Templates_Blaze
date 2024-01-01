#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
P2015 Two-pronged Apple Tree

Find q edges from the root of the tree downwards so that
the number of apples obtained in the end is the largest,
and the final result must be a complete tree.
*/

const int MAXN = 200;
int n, q;
vector<vector<pair<int, int>>> edge;
/*
sum[i] records the total number of edges
of the subtree rooted at the point
*/
int sum[MAXN];
int dp[MAXN][MAXN];

void indfs(int node, int parent) {
    for (auto z : edge[node]) {
        if (z.first != parent) {
            int v = z.first, w = z.second;
            indfs(v, node);
            //The total number of edges on the subtree
            sum[node] += sum[v] + 1;
            // sum[node] is the total number of edges on the subtree rooted at u
            // for (int j = sum[node]; j >= 0; --j)
            // Use k to traverse different partitions
            // for (int k = 0; k <= j - 1; ++k)
            // two fors are optimized to the following code. No need to optimize
            for (int j = min(q, sum[node]); j >= 0; --j)
            {
                for (int k = 0; k <= min(sum[v], j - 1); ++k)
                {
                    dp[node][j] = max(dp[node][j], dp[v][k] + dp[node][j - k - 1] + w);
                }
            }
        }
    }
}

void solve() {
    cin >> n >> q; // n points, leaving q branches

    edge.resize(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int u, v, W;
        cin >> u >> v >> W;
        edge[u].push_back({v, W});
        edge[v].push_back({u, W});
    }

    indfs(1, 0);
    cout << dp[1][q] << endl;
    return;
}

int main()
{
    blaze;
    // int _t; cin >> _t; while (_t--)
    solve();
    return 0;
}