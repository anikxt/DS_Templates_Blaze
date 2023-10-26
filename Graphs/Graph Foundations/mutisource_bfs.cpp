#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
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
    int _t = 1;
    // cin >> _t;
    while (_t--) {
        solve();
    }
    return 0;
}