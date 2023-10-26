#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*

Design a DS

N arr

Query:
1 + x -> add x to set
2 - x -> remove x if exist
3 - ? k -> find kth

*/

int n;

int t[400400];

int merge(int a, int b) {
    return a + b;
}

void update(int index, int l, int r, int val, int par) {
    // if (val < l or val > r)
    //     return;

    if (l == r) {
        t[index] = par;
        return;
    }

    int mid = (l + r) / 2;
    if (val <= mid)
        update(index * 2, l, mid, val, par);
    else update(index * 2 + 1, mid + 1, r, val, par);
    t[index] = merge(t[index * 2], t[index * 2 + 1]);
}

int queryKth(int index, int l, int r, int k) {
    if (l == r)
        return l;

    int mid = (l + r) / 2;
    if (k <= t[2 * index])
        return queryKth(2 * index, l, mid, k);
    else
        return queryKth(index * 2 + 1, mid + 1, r, k - t[2 * index]);
}

void solve()
{
    int n;
    cin >> n;
    const int N = 1e5;

    int q;
    cin >> q;
    while (q--) {
        char ch;
        cin >> ch;
        if (ch == '?') {
            int k;
            cin >> k;
            cout << queryKth(1, 0, N, k) << endl;
        } else {
            int v;
            cin >> v;
            if (ch == '+')
                update(1, 0, N, v, 1);
            else update(1, 0, N, v, 0);
        }
    }

    return;
}

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

/*

4
7
+ 1
+ 2
? 2
+ 3
? 2
- 2
? 2
+ 5
? 3
? 2
- 3
? 2

*/