#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
P2585 [ZJOI2006] Three-color binary tree

First of all, our DP process is based on tree,
so we need to build a binary tree first.
Next, we set the state, f(i, j),
to represent the maximum number of green nodes
that are painted with color j at the i-th node.
Because the parent node cannot have the same color as the child node,
and the colors of the two child nodes cannot be the same,
so we can get the following state transition equation:

f(i, j) = max k,l∈children{i}{f(k, x) + f(l, y)}(j != x != y)


Here k, l are the child nodes of i, and x, y are possible colors.
At the same time, there are two possible colors for the child nodes.
If j = green, the initial value of f(i, j) should be set to 1.
*/

const int N = 500500;
const int red = 1, green = 2, blue = 3;

struct node {
    int child[3];
} tree[N];

int fx[N][4], fn[N][4];
char c[N];

void dfs(int node) {
    // max
    fx[node][red] = 0;
    fx[node][green] = 1; // default set as 1
    fx[node][blue] = 0;

    // min
    fn[node][red] = 0;
    fn[node][green] = 1; // default set as 1
    fn[node][blue] = 0;

    for (int i = 1; i <= 2; ++i)
    {
        if (tree[node].child[i] != 0) {
            dfs(tree[node].child[i]);
        }
    }

    int lc = tree[node].child[1];
    int rc = tree[node].child[2];

    // max
    fx[node][green] += max(fx[lc][red] + fx[rc][blue], fx[lc][blue] + fx[rc][red]);
    fx[node][red] += max(fx[lc][green] + fx[rc][blue], fx[lc][blue] + fx[rc][green]);
    fx[node][blue] += max(fx[lc][red] + fx[rc][green], fx[lc][green] + fx[rc][red]);

    // min
    fn[node][green] += min(fn[lc][red] + fn[rc][blue], fn[lc][blue] + fn[rc][red]);
    fn[node][red] += min(fn[lc][green] + fn[rc][blue], fn[lc][blue] + fn[rc][green]);
    fn[node][blue] += min(fn[lc][red] + fn[rc][green], fn[lc][green] + fn[rc][red]);
}

int it = 0;
void build() {
    int tmp = ++it;
    if (c[tmp] == '1') {
        tree[tmp].child[1] = it + 1;
        build();
        return;
    }

    if (c[tmp] == '2') {
        tree[tmp].child[1] = it + 1;
        build();
        tree[tmp].child[2] = it + 1;
        build();
        return;
    }
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = n; i >= 1; --i)
    {
        c[i] = s[i - 1];
    }

    build();
    dfs(1);

    cout << max({fx[1][red], fx[1][green], fx[1][blue]}) << " ";
    cout << min({fn[1][red], fn[1][green], fn[1][blue]}) << " ";
    cout << endl;
    return;
}

int main()
{
    blaze;
    // int _t; cin >> _t; while (_t--)
    solve();
    return 0;
}