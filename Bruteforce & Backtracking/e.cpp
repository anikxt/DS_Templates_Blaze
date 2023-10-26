#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Knights - 2 (Choices)

int n, k;
int ans;

int board[14][14];

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2};

bool check1(int i, int j) {
   if (board[i][j] == 1)return 0;
   for (int pos = 0; pos < 8; ++pos)
   {
      int nx = i + dx[pos];
      int ny = j + dy[pos];
      // (nx, ny) -> are the cells getting attacked
      if ((nx >= 0 and nx < n) and (ny >= 0 and ny < n) and board[nx][ny] == 1)return 0;
   }
   return 1;
}

void rec(int level, int knights) {
   if (level == n * n) {
      if (knights == 0)ans++;
      return;
   }

   int row = level / n;
   int col = level % n;

   // don't place a knight
   rec(level + 1, knights);

   // place a knight
   if (knights > 0 and check1(row, col)) {
      board[row][col] = 1;
      rec(level + 1, knights - 1);
      board[row][col] = 0;
   }
}

void solve()
{
   cin >> n >> k;
   ans  = 0;
   rec(0, k);
   cout << ans << endl;
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