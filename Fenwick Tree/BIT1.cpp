#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
BIT I: Single Modify, Interval Query

Sequence a1, a2, ..., an

Query q -
1 i x -> add x to a[i]
2 l r -> print Summ. (a[l] + a[l + 1] + ... + a[r])

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
void update(int i, int p) {
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

    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        update(i, x);
    }

    int opt, l, x;
    while (q--) {
        cin >> opt >> l >> x;

        if (opt == 1) {
            update(l, x);
        } else {
            cout << getsum(x) - getsum(l - 1) << endl;
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