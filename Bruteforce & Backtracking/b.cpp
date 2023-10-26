#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int n, k;
vector<int> arr;

vector<int> sol;
void rec(int level) {
   // base case
   if (level == n) {
      if (sol.size() == k) {
         for (auto v : sol) {
            cout << v << " ";
         }
         cout << endl;
      }
      return;
   }

   //recursive case
   // decide for arr[level]...

   // take
   sol.push_back(arr[level]);
   rec(level + 1);
   sol.pop_back();

   // don't take
   rec(level + 1);
}

void solve()
{
   cin >> n >> k;
   arr.resize(n);
   for (int i = 0; i < n; ++i)
   {
      cin >> arr[i];
   }

   rec(0);
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