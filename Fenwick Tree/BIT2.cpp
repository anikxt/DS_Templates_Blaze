#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
BIT II: Interval Modification, Single Point Query

Sequence a1, a2, ..., an

Query q -
1 l r x -> add x to (a[l], a[l + 1], ..., a[r])
2 i -> find a[i]

Constraints:
1 <= n, q <= 1e6
1 <= a[i] <= 1e6
1 <= l, r <= n
|x| <= 1e6
*/

#define lowbit(x) (x & -x)
#define int long long
const int MAXN = 1e6 + 10;
int n, q;
int tr[MAXN];

// add p to position i
void add(int i, int p) {
    while (i <= n) {
        tr[i] += p; // updated the affected tree[i]
        i += lowbit(i);
    }
}

int getsum(int i) {
    int res = 0;

    while (i > 0) {
        res += tr[i];
        i -= lowbit(i);
    }

    return res;
}

void solve() {
    cin >> n >> q;

    /*
    pre = x: Updates pre to the current value of x to prepare for the next iteration.
    Purpose of This Code:

    Primary goal: to construct the initial Fenwick tree based on the input sequence.
    It does this by adding the differences between consecutive elements to the tree,
    effectively building a representation of prefix sums.
    This approach allows for efficient range queries and updates later on,
    as the Fenwick tree stores cumulative sums.
    */

    int x, pre = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        add(i, x - pre);
        pre = x;
    }

    int opt, u, v;
    while (q--) {
        cin >> opt >> u;

        if (opt == 1) {
            int a;
            cin >> v >> a;
            add(u, a), add(v + 1, -a);
        } else {
            cout << getsum(u) << endl;
        }
    }

    return;
}
#undef int

int main()
{
    blaze;
    // int _t; cin >> _t; while (_t--)
    solve();
    return 0;
}