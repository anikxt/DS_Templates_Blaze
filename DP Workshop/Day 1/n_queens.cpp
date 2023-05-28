#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
typedef long long int ll;
#define gc getchar_unlocked
#define fab(i, a, b) for (int i = a; i <= b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define clr(x, y) memset(x, y, sizeof(x))
#define sortall(x) sort(all(x))
#define vll vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;

const int MOD = 1e9 + 7;
//=======================

int n;

int queen[20]; // queen[i] -> where is my queen in row i.

bool check(int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        int prow = i;
        int pcol = queen[i];

        if (pcol == col or abs(col - pcol) == abs(row - prow))
        {
            return false;
        }
    }
    return true;
}

int rec(int level) // return -> number of ways to populate [level..n-1] rows for a valid configuration
{
    // level -> row in which we are placing the queen

    // pruning

    // basecase
    if (level == n)
    {
        return 1;
    }

    // compute
    int ans = 0;
    // loop over all choices
    for (int col = 0; col < n; ++col)
    {
        // check if the choice is valid
        if (check(level, col))
        {
            // place the queen
            queen[level] = col;
            // explore the option
            ans += rec(level + 1);
            // revert placing the queen
            queen[level] = -1;
        }
    }

    // return
    return ans;
}

void solve()
{
    cin >> n;
    memset(queen, -1, sizeof(queen));
    cout << rec(0) << endl;
    return;
}

int main()
{
    blaze;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}