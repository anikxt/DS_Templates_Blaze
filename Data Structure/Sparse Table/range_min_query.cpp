#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Range Minimum Query - Sparse Table
// can also be used with min, max, gcd

#define int long long
const int MAXN = 1e5 + 5, MOD = 1e9 + 7, INF = 1e18;
const int LOG = 17;
int a[MAXN];
int m[LOG][MAXN]; // m[j][i] is minimum among a[i..i+^j-1]
int bin_log[MAXN];

int query(int L, int R) { // O(1)
    int length = R - L + 1;
    int k = bin_log[length];
    // int k = 31 - __builtin_clz(length);
    return min(m[k][L], m[k][R - (1 << k) + 1]);
}

void solve() {
    // 1) read input
    int n;
    cin >> n;
    bin_log[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        bin_log[i] = bin_log[i / 2] + 1;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        m[0][i] = a[i];
    }

    // 2) pre-preocessing, O(N*log(N))
    for (int k = 1; k < LOG; ++k)
    {
        for (int i = 0; i + (1 << k) - 1 < n; ++i)
        {
            m[k][i] = min(m[k - 1][i], m[k - 1][i + (1 << (k - 1))]);
        }
    }

    // 3) answer query
    int q;
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        cout << query(L, R) << endl;
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