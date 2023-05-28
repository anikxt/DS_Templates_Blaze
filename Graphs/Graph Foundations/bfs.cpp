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

/*
S.#...
......
......
####.#
E.##.#
..#..#
#....#
*/

vector<string> arr;
int n, m;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool inside(int x, int y) {
    if (x<0 or x >= n or y<0 or y >= m or arr[x][y] == '#')
        return 0;
    return 1;
}

pii dist[1010][1010];
pii par[1010][1010];

void bfs(pii st) {
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            dist[i][j] = {1e9, 0};
        }
    }

    dist[st.f][st.s] = {0, 1}; // {current distance, no. of optimal path till this point}
    queue<pii> q;
    q.push(st);
    while (!q.empty()) {
        // pehle mark phir push
        pii cur = q.front();
        q.pop();
        int curd = dist[cur.f][cur.s].f;
        for (int k = 0; k < 4; ++k)
        {
            if (!inside(cur.f + dx[k], cur.s + dy[k]))
                continue;
            pii neigh = {cur.f + dx[k], cur.s + dy[k]};
            if (dist[neigh.f][neigh.s].f > curd + 1) { // relax
                dist[neigh.f][neigh.s] = {curd + 1, dist[cur.f][cur.s].s};
                par[neigh.f][neigh.s] = cur;
                q.push(neigh);
            } else if (dist[neigh.f][neigh.s].f == curd + 1) {
                dist[neigh.f][neigh.s].s += dist[cur.f][cur.s].s;
            }
        }

    }
}

void solve()
{
    cin >> n >> m;
    arr.resize(n + 1);
    pii st, en;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        for (int j = 0; j < m; ++j)
        {
            if (arr[i][j] == 'S') {
                st = {i, j};
            } else if (arr[i][j] == 'E') {
                en = {i, j};
            }
        }
    }

    bfs(st);
    cout << dist[en.f][en.s].f << " " << dist[en.f][en.s].s << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m; ++j)
    //     {
    //         cout << dist[i][j].f << "\t";
    //     }
    //     cout << endl;
    // }

    // pii temp = en;
    // vector<pii> path;
    // while (temp != st) {
    //     path.push_back(temp);
    //     temp =  par[temp.f][temp.s];
    // }
    // path.push_back(st);
    // reverse(all(path));
    // for (auto v : path) {
    //     cout << v.f << " " << v.s << endl;
    // }
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