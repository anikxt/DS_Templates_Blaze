#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
BIT III: Interval Modification, Interval Query

Sequence a1, a2, ..., an

Query q -
1 l r x -> add x to (a[l], a[l + 1], ..., a[r])
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
int tr1[MAXN], tr2[MAXN];

// add p to position i
void add(int i, int p) {
    int x = i;
    while (i <= n) {
        tr1[i] += p; // updated the affected tree[i]
        tr2[i] += p * (x - 1);
        i += lowbit(i);
    }
}

int getsum(int i) {
    int res = 0;
    int x = i;
    while (i > 0) {
        res += tr1[i] * x - tr2[i];
        i -= lowbit(i);
    }

    return res;
}

void solve() {
    cin >> n >> q;

    int x, pre = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        add(i, x - pre);
        pre = x;
    }

    int opt, u, v;
    while (q--) {
        cin >> opt >> u >> v;

        if (opt == 1) {
            int a;
            cin >> a;
            add(u, a), add(v + 1, -a);
        } else {
            cout << getsum(v) -  getsum(u - 1) << endl;
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