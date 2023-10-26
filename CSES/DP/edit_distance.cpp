#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

#define int long long
int n, m;
string a, b;
int dp[5010][5010];

void solve()
{
    cin >> a >> b;
    n = a.length(), m = b.length();
    for (int i = n; i >= 0; --i)
    {
        for (int j = m; j >= 0; --j)
        {
            if (i == n or j == m) {
                // if anyone of them has ended then the other one has to be done with inserts or deletes
                dp[i][j] = (n - i) + (m - j);
            } else {
                dp[i][j] = min({1 + dp[i][j + 1],
                                1 + dp[i + 1][j],
                                dp[i + 1][j + 1] + (a[i] == b[j] ? 0 : 1)
                               });
            }
        }
    }

    cout << dp[0][0] << endl;
    return;
}
#undef int

int main()
{
    blaze;
    int _t = 1;
    cin >> _t;
    while (_t--) {
        solve();
    }
    return 0;
}
