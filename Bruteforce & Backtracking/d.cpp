#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Knights - 1 / K Knights

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

void rec(int level, int lastx, int lasty) { // level = no. of knights placed
   if (level == k) {
      ans++;
      // board gives the solution
      return;
   }

   // choices
   for (int i = lastx; i < n; ++i)
   {
      for (int j = 0; j < n; ++j)
      {
         // check
         if (i == lastx and j <= lasty)continue;
         if (check1(i, j)) {
            // move
            board[i][j] = 1;
            rec(level + 1, i, j);
            board[i][j] = 0;
         }
      }
   }
}

void solve()
{
   cin >> n >> k;
   ans = 0;
   rec(0, 0, -1);
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