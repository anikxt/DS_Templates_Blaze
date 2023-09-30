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

// bfs coding test - chor police

/*
6 6
S.....
.W.W.W
R..W..
......
.D....
E.....

13
*/

int n, m;
vector<string> arr;
char dirchar[] = {'U', 'R', 'D', 'L'};
int dx[] = { -1, 0, +1, 0};
int dy[] = {0, +1, 0, -1};

bool check(int x, int y) { // is a valid cell
    if (x >= 0 and x < n and y >= 0 and y < m and arr[x][y] != 'W')return 1;
    return 0;
}

void process(vector<pair<int, int>> pos[]) {
    for (int dir = 0; dir < 4; ++dir)
    {
        for (auto v : pos[dir]) {
            int x = v.first + dx[dir], y = v.second + dy[dir];
            while (check(x, y) and arr[x][y] != dirchar[dir]) {
                if (arr[x][y] == '.')
                    arr[x][y] = 'B';
                x += dx[dir];
                y += dy[dir];
            }
        }
        for (auto v : pos[dir]) {
            int x = v.first, y = v.second;
            arr[x][y] = 'B';
        }
    }
}

using state = pair<int, int>;
vector<vector<int>> dist;
vector<vector<state>> par;

void updatePath(state en) {
    while (en != make_pair(-1, -1)) {
        if (arr[en.f][en.s] == '.')
            arr[en.f][en.s] = 'P';
        en = par[en.f][en.s];
    }
}

int bfs(state st, state en) {
    queue<state> q;
    dist.assign(n, vector<int>(m, 1e9));
    par.assign(n, vector<state>(m, make_pair(-1, -1)));
    dist[st.f][st.s] = 0;
    q.push(st);
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
            int x = cur.f + dx[dir];
            int y = cur.s + dy[dir];
            if (check(x, y) and arr[x][y] != 'B' and dist[x][y] == 1e9) {
                par[x][y] = cur;
                dist[x][y] = dist[cur.f][cur.s] + 1;
                q.push(make_pair(x, y));
            }
        }
    }
    if (dist[en.f][en.s] == 1e9)return -1;
    else {
        updatePath(en);
        return dist[en.f][en.s];
    }
}

void solve()
{
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    pii st, en;
    vector<pii> pos[4]; // U, R, D, L

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (arr[i][j] == 'S') {
                st = {i, j};
            } else  if (arr[i][j] == 'E') {
                en = {i, j};
            } else  if (arr[i][j] == 'U') {
                pos[0].push_back({i, j});
            } else  if (arr[i][j] == 'R') {
                pos[1].push_back({i, j});
            } else  if (arr[i][j] == 'D') {
                pos[2].push_back({i, j});
            } else  if (arr[i][j] == 'L') {
                pos[3].push_back({i, j});
            }
        }
    }

    process(pos);
    cout << bfs(st, en) << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << endl;
    }

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