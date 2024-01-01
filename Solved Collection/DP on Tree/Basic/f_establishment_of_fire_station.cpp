#include<bits/stdc++.h>
using namespace std;

/*
P2279 [HNOI2003] Establishment of fire station

Problem:
N bases are distributed in a tree shape.
Now we need to select some bases as fire stations.
The range that the fire station can protect is all points
that are no more than 2 points away from it.
Here we define the length of each side to be 1.
A solution is now required to protect all bases.
As few fire stations as possible need to be built.

The meaning of the question?
This is a problem of selecting points to cover
the entire picture of the tree-shaped DP of the comparison board ~

The "covering" mentioned in this question generally means
that when the relative position of one point and another point
reaches a certain relationship , one point can be said
to cover another point.

Solution:
Find the node with the deepest depth

For a leaf node, cover itself: self, brother, father, grandfather

But be sure to choose the grandpa node because it covers the most

Find the node with the deepest depth,
place troops at his grandfather's position,
delete all nodes where his grandfather can be placed,
and continue to operate on the remaining nodes
until the output is empty.

Heap maintenance
*/

const int N = 1005;
int n, ans;
vector<vector<int>>g;
int par[N], vis[N];

struct node {
    int depth, id;
} d[N];

bool cmp(node a, node b)
{
    return a.depth > b.depth;
}

void dfs(int node, int parent, int dep)
{
    d[node].depth = dep;
    par[node] = parent;
    for (auto v : g[node])
    {
        if (v != parent) {
            dfs(v, node, dep + 1);
        }
    }
}

void era(int node, int parent, int dis)
{
    if (dis > 2)return;

    vis[node] = true;
    for (auto v : g[node])
    {
        if (v != parent)
            era(v, node, dis + 1);
    }
}

int main()
{
    cin >> n;
    par[1] = 1;
    d[1].id = 1;
    d[1].depth = 1;

    g.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        d[i].id = i;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    dfs(1, 1, 1);
    sort(d + 1, d + n + 1, cmp);

    for (int i = 1; i <= n; i++)
    {
        if (vis[d[i].id])continue;
        int grand = par[par[d[i].id]];
        era(grand, grand, 0);
        ans++;
    }

    cout << ans << endl;
    return 0;
}