#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
Two Kingdoms

Description:
In a board of dimensions N x M, each cell is colored with color Cij.
Now, You need to select a connected set of cells from the board
such that the Number of Distinct colored cells in the set is at most 2.
Two cells are called connected if they share an edge.
A pair of cells in the connected set should either
be connected directly or indirectly via some connected path.
find out the size of the maximum connected set of cells that you can create.

Input Format:
The first line contains the Dimensions of the board, N and M.
The next N line contains the M integers each.
jth integer on ith Line denoting the colours of the cell Cij .

Output Format:
Single integer, denoting the size of maximum number of cells in a connected Set.

Constraints:
1 <= N , M <= 1000
1 <= Cij <= 1000000

Sample Input:
3 3
1 2 5
1 4 4
3 6 4

Sample Output:
5
*/

#define int long long
using ii = pair<int, int>;
struct DSU {
    int n;
    vector<int> par, sz;
    vector<pair<int, int>> st; // stores the edges merged
    multiset<int> compSize;
    DSU() {}

    void init(int a) {
        n = a;
        par.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(par.begin(), par.end(), 0);
        for (int i = 0; i <= n; ++i)
        {
            compSize.insert(1);
        }
    }

    // without path compression
    int find(int x) {
        if (x == par[x])
            return x;
        return find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        compSize.erase(compSize.find(sz[x]));
        compSize.erase(compSize.find(sz[y]));
        sz[x] += sz[y];
        par[y] = x;
        // y merged into x
        compSize.insert(sz[x]);
        st.push_back(make_pair(y, x)); // sz[y] is smaller
    }

    void rollback() {
        while (!st.empty()) {
            // start from last merged edge
            int y = st.back().first; // sz[y] is smaller
            int x = st.back().second;
            st.pop_back();
            compSize.erase(compSize.find(sz[x]));
            par[y] = y;
            sz[x] -= sz[y];
            compSize.insert(sz[x]);
            compSize.insert(sz[y]);
        }
    }

    int get_max() {
        auto it = compSize.end();
        it--;
        return *it;
    }
} dsu;

int n, m;
int arr[1010][1010];
int node[1010][1010];
int dx[4] = { 1, 0, 0, -1}; // down right up left
int dy[4] = { 0, 1, -1, 0};

bool check(int x, int y) {
    return (x >= 0 and x < n and y >= 0 and y < m);
}

vector<pair<ii, ii>> edges;

void solve()
{
    cin >> n >> m;
    dsu.init(n * m);
    int cnt = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
            node[i][j] = cnt++;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (check(x, y)) {
                    int c1 = arr[i][j];
                    int c2 = arr[x][y];
                    if (c1 > c2)
                        swap(c1, c2);
                    if (c1 != c2) {
                        edges.push_back({{c1, c2}, {node[i][j], node[x][y]}});
                    } else {
                        dsu.unite(node[i][j], node[x][y]);
                    }
                }
            }
        }
    }

    /* since the same color mergings are not going to get reverted,
     so clear the stack */
    dsu.st.clear();
    sort(all(edges));
    int ans = dsu.get_max();
    for (int i = 0; i < edges.size(); ++i)
    {
        int j = i;
        while (j < edges.size() and edges[i].first == edges[j].first) {
            dsu.unite(edges[j].second.first, edges[j].second.second);
            j++;
        }
        ans = max(ans, dsu.get_max());
        dsu.rollback();
        i = j - 1;
    }

    cout << ans << endl;
    return;
}
#undef int

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