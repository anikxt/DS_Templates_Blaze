#include <bits/stdc++.h>
#define F first
#define S second
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
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
    if (x < 0 or x >= n or y < 0 or y >= m or arr[x][y] == '#')
        return 0;
    return 1;
}

pair<int, int> dist[1010][1010];
pair<int, int> par[1010][1010];

void bfs(pair<int, int> st) {
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            dist[i][j] = {1e9, 0};
        }
    }

    dist[st.F][st.S] = {0, 1}; // {current distance, no. of optimal path till this point}
    queue<pair<int, int>> q;
    q.push(st);
    while (!q.empty()) {
        // pehle mark phir push
        pair<int, int> cur = q.front();
        q.pop();
        int curd = dist[cur.F][cur.S].F;
        for (int k = 0; k < 4; ++k)
        {
            if (!inside(cur.F + dx[k], cur.S + dy[k]))
                continue;
            pair<int, int> neigh = {cur.F + dx[k], cur.S + dy[k]};
            if (dist[neigh.F][neigh.S].F > curd + 1) { // relax
                dist[neigh.F][neigh.S] = {curd + 1, dist[cur.F][cur.S].S};
                par[neigh.F][neigh.S] = cur;
                q.push(neigh);
            } else if (dist[neigh.F][neigh.S].F == curd + 1) {
                dist[neigh.F][neigh.S].S += dist[cur.F][cur.S].S;
            }
        }

    }
}

void solve()
{
    cin >> n >> m;
    arr.resize(n + 1);
    pair<int, int> st, en;
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
    cout << dist[en.F][en.S].F << " " << dist[en.F][en.S].S << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m; ++j)
    //     {
    //         cout << dist[i][j].F << "\t";
    //     }
    //     cout << endl;
    // }

    // pair<int,int> temp = en;
    // vector<pair<int,int>> path;
    // while (temp != st) {
    //     path.push_back(temp);
    //     temp =  par[temp.F][temp.S];
    // }
    // path.push_back(st);
    // reverse(all(path));
    // for (auto v : path) {
    //     cout << v.F << " " << v.S << endl;
    // }
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