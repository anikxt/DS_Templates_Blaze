#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
P1273 Cable TV network

Bare tree grouping backpack...

We design f[i][j] as a subtree with i as the root,
and select the maximum benefit of j leaf nodes.

The transfer is very obvious f[i][j] = f[i][j - k] + f[son][k] - w

However, there is a detail when we transfer, that is,
j needs to use the data of j - k,
so we can enumerate j in reverse order to avoid data overwriting.

Initialization: For all leaf nodes f[i][1] = w[i].

The remaining nodes are assigned the value -inf.
*/

const int N = 3030;
int n, m;
int dp[N][N];
/*
sz array represents how many leaves are there in a subtree
*/
int sz[N];
vector<vector<pair<int, int>>> edge;

void indfs(int node , int parent) {
    for (auto z : edge[node]) {
        int v = z.first;
        if (v != parent) {
            indfs(v , node);
            sz[node] += sz[v];
        }
    }

    for (auto z : edge[node]) {
        int v = z.first , w = z.second;
        if (v != parent) {
            for (int j = sz[node] ; j >= 1 ; j -- ) {
                /*
                When k equals 0️⃣, it means that it has no impact on the value
                of the father node, so it can be ignored. enumerate to update
                */
                for (int k = 1 ; k <= sz[v] ; ++ k) {
                    /*
                    When there are k leaves, the father's temp profit should be:
                    [Profit from the k leaves contributed by this son] +
                    [Profit from the remaining leaves contributed by the previous leaf nodes -
                    [It takes the father to build a road to his son] cost]
                    */
                    dp[node][j] = max(dp[node][j] , dp[node][j - k] + dp[v][k] - w);
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    edge.resize(n + 1);
    for (int i = 1 ; i <= n - m ; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j)
        {
            int v , w;
            cin >> v >> w;
            edge[i].push_back({v, w});
            edge[v].push_back({i, w});
        }
    }

    for (int i = 1; i <= n ; ++ i)
        for (int j = 1; j <= m ; ++ j)
            dp[i][j] = -1e9;

    for (int i = n - m + 1 ; i <= n ; ++ i) {
        cin >> dp[i][1];
        sz[i] = 1;
    }

    indfs(1 , 0);

    int ans = 0;
    for (int i = sz[1] ; i >= 1 ; --i) {
        if (dp[1][i] >= 0) {
            ans = i;
            break;
        }
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