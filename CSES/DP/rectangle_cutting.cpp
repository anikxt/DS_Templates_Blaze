#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int n, m;
int dp[1010][1010];

void solve()
{
    cin >> n >> m;
    for (int x = 1; x <= 500; ++x)
    {
        for (int y = 1; y <= 500; ++y)
        {
            if (x == y) {
                dp[x][y] = 0;
            } else {
                dp[x][y] = 1e9;
                for (int a = 1; a <= x - 1; ++a)
                {
                    dp[x][y] = min(dp[x][y], dp[a][y] + dp[x - a][y] + 1);
                }

                for (int b = 1; b <= y - 1; ++b)
                {
                    dp[x][y] = min(dp[x][y], dp[x][b] + dp[x][y - b] + 1);
                }
            }
        }
    }

    cout << dp[n][m] << endl;
    return;
}

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
