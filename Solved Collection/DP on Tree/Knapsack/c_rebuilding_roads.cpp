#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
P1272 Rebuilding roads

Algorithm: Tree DP

Define
dp[i][j] to represent the number of edges
that need to be deleted to obtain a subtree of size j at node i.

Then we first do dfs and find the number of nodes in each subtree,
then dp[i][1] is the number of sons of i.

The transfer equation is:
dp[i][j]=max(dp[i][j], dp[i][j−k] + dp[v][k] − 1)

Why reduce it by one?
Because the edge connecting the v and i nodes is not considered,
it obviously cannot be removed,
so the number of removed edges must be subtracted by 1.
*/

const int N = 200;
int n, p;
vector<vector<int>> g;
int dp[N][N];
int indeg[N], sz[N], par[N];

//dp[i][j] is the minimum cost to retain j tree in the subtree rooted at i
void indfs(int node, int parent) {
    sz[node]++;
    for (auto v : g[node]) {
        if (v != parent) {
            indfs(v, node);
            sz[node] += sz[v];
        }
    }

    int sumn = 1;
    dp[node][sz[node]] = 0;
    for (auto v : g[node]) {
        if (v != parent) {
            // sumn records how many children there are (including yourself)
            sumn += sz[v];
            //can cut sumn times at most
            for (int j = sumn; j >= 1; --j)
            {
                for (int k = 1; k < j; ++k)
                {
                    //If you cut k times less, you have to cut it back in the sub-tree.
                    dp[node][j] = min(dp[node][j], dp[node][j - k] + dp[v][k] - 1);
                }
            }
        }
    }
}

void solve() {
    cin >> n >> p;

    memset(dp, 20, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        dp[i][1] = 0;
    }

    g.resize(n + 1);
    for (int i = 1; i <= n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
        dp[a][1]++; // record how many son i has
        /*
        beacause the subtree rooted at i retains one node,
        all its son must be cut off
        */
    }

    int root;
    for (int i = 1; i <= n; ++i)
    {
        if (indeg[i] == 0)
            root = i;
    }

    indfs(1, 0);

    int ans = dp[root][p];
    for (int i = 1; i <= n; ++i)
    {
        /*
        If you want to retain the subtree,
        you need to cut more edges connected to the parent node
        */
        ans = min(ans, dp[i][p] + 1);
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