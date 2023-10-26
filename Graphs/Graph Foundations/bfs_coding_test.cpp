#include <bits/stdc++.h>
#define F first
#define S second
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
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
        if (arr[en.F][en.S] == '.')
            arr[en.F][en.S] = 'P';
        en = par[en.F][en.S];
    }
}

int bfs(state st, state en) {
    queue<state> q;
    dist.assign(n, vector<int>(m, 1e9));
    par.assign(n, vector<state>(m, make_pair(-1, -1)));
    dist[st.F][st.S] = 0;
    q.push(st);
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
            int x = cur.F + dx[dir];
            int y = cur.S + dy[dir];
            if (check(x, y) and arr[x][y] != 'B' and dist[x][y] == 1e9) {
                par[x][y] = cur;
                dist[x][y] = dist[cur.F][cur.S] + 1;
                q.push(make_pair(x, y));
            }
        }
    }
    if (dist[en.F][en.S] == 1e9)return -1;
    else {
        updatePath(en);
        return dist[en.F][en.S];
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

    pair<int, int> st, en;
    vector<pair<int, int>> pos[4]; // U, R, D, L

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
    int _t = 1;
    // cin >> _t;
    while (_t--) {
        solve();
    }
    return 0;
}