#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Time complexity - O(N!)
// O(Ch1*Ch2*...*Chn*(Base Complexity + SUMM(Checks in all levels)))

int n, cnt;
vector<int> queens;

bool check(int row, int col) {
   for (int prow = 0; prow < row; ++prow)
   {
      int pcol = queens[prow];
      // (row, col) (prow, pcol)
      if (pcol == col or abs(row - prow) == abs(col - pcol)) // attack condition
      {
         return 0;
      }
   }
   return 1;
}

void rec(int level) { // level is row
   // base case
   if (level == n) {
      cnt++;
   }
   // recursive case
   for (int col = 0; col < n; ++col) // loop over choices
   {
      if (check(level, col)) { // check
         // place/move
         queens.push_back(col);
         rec(level + 1);
         queens.pop_back();
      }
   }
}

void solve()
{
   cin >> n;
   rec(0);
   cout << cnt << endl;
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