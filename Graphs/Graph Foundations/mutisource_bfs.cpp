#include <bits/stdc++.h>
typedef long long int ll;
#define gc getchar_unlocked
#define fab(i, a, b) for (int i = a; i <= b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define pr(v) for(auto &z: v) cout << z << ' '; cout << '\n'
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
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
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
ll lcm(ll x, ll y) { ll res = x / __gcd(x, y); return (res * y);}
//=======================

// Nearest Power Station - Multisource BFS (pseudo node concept)

/*
5 5
...X.
PX.XX
.XP..
....X
...P.
*/

const int N = 1001;
const int INF = 1e9;

string grid[N];
int dist[N][N];
int n, m;
pair<int, int> closest_power_station[N][N];

int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int i, int j) {
    if (i >= 0 and i < n and j >= 0 and j < m) {
        if (grid[i][j] != 'X')
            return true;
    }
    return false;
}

void bfs() {
    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 'P') {
                q.push({i, j});
                dist[i][j] = 0;
                closest_power_station[i][j] = {i, j};
            }
        }
    }

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        int cur_i = it.first;
        int cur_j = it.second;

        for (int i = 0; i < 4; ++i)
        {
            int nxt_i = cur_i + dx[i];
            int nxt_j = cur_j + dy[i];

            if (isValid(nxt_i, nxt_j)) {
                if (dist[nxt_i][nxt_j] > dist[cur_i][cur_j] + 1) {
                    dist[nxt_i][nxt_j] = dist[cur_i][cur_j] + 1;
                    closest_power_station[nxt_i][nxt_j] = closest_power_station[cur_i][cur_j];
                    q.push({nxt_i, nxt_j});
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            dist[i][j] = INF;
        }
    }

    bfs();

    cout << "Closest distance:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dist[i][j] != INF) {
                cout << dist[i][j] << " ";
            } else {
                cout << -1 << " ";
            }
        }
        cout << endl;
    }
    cout << endl;

    cout << "Closest Power Station:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dist[i][j] != INF) {
                auto it = closest_power_station[i][j];
                cout << "(" << it.first << ", " << it.second << ") ";
            } else {
                cout << "(-1,-1) ";
            }
        }
        cout << endl;
    }
    cout << endl;
    return;
}

int main()
{
    blaze;
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