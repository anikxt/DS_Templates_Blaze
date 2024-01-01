#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
P2014 [CTSC1997] Course Selection

Problem Statement:
There are N courses, and each course has corresponding credits.
However, some courses have prerequisite courses.
Find the maximum number of credits that can be obtained
by taking M courses.

Solution:
The title mentions that each course has at most
one direct prerequisite course. Connecting the prerequisite courses
of each course to it will form one or more trees.
For this purpose, we can create a node No. 0 and
connect the root nodes of all trees to node No. 0.
The credit of node 0 is 0, and the number of elective courses allowed
is increased by one.

After splicing the forest into a tree,
we need to perform dynamic programming on the tree.

Consider each node in the tree:
this node may be the parent of one or more nodes (prerequisite course),
or it may not be. Use f[i][j] to represent the maximum credits
that can be obtained by choosing j courses for node i
(j subjects include itself). The prerequisite for selecting
all its child nodes is that this node must be selected,
so f[i][1] must be equal to the weight (credit) of the i node

Traverse all child nodes of i node in a certain order.
When traversing to the x node, we assume that we have obtained
all f[x][k] values. Since f[i][k] does not have the weight of
the x node and its subtree, the f array of the i node
can be updated through the x node.
That is, f[i][k] = max(f[i][k], f[i][k - p] + f[x][p])
(1 ≤ k ≤ m , 0 ≤ p < k)

The reason p < k is that when p = k,
the value of k - p in f[i][k - p] is equal to 0,
which means that the i node cannot be selected.
Since i is the prerequisite course for the x node,
The x node cannot be selected without selecting the i node,
so p < k should be satisfied

When enumerating k, you need to pay attention:
since f[i][k] is updated from f[i][k - p],
then you need to ensure that f[i][k] is updated
when f[i][k - p] has not been updated.
Since p is a positive integer, we can enumerate k in reverse order.
*/

const int N = 1000;
int n, m;
vector<vector<int>> g;
vector<int> cre;

int dp[N][N];

void indfs(int node, int parent) {
    dp[node][1] = cre[node];
    for (auto v : g[node]) {
        if (v != parent) {
            indfs(v, node);
        }
    }

    for (auto v : g[node]) {
        if (v != parent) {
            /*
            This is the same as the 0-1 knapsack,
            the total weight cycles from large to small
            */
            for (int j = m + 1; j >= 1; --j)
            {
                /*
                Here is the difference,
                the weight of the child nodes needs to be specified
                */
                for (int k = 0; k < j; ++k)
                {
                    /*
                    This function sets the previous parameter to
                    the maximum value of the two
                    */
                    dp[node][j] = max(dp[node][j], dp[node][j - k] + dp[v][k]);
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    ++m;

    g.resize(n + 1), cre.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
        cin >> cre[i];
    }

    indfs(0, -1);
    cout << dp[0][m] << endl;
    return;
}

int main()
{
    blaze;
    // int _t; cin >> _t; while (_t--)
    solve();
    return 0;
}