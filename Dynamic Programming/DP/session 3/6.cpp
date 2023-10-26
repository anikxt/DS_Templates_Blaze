#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// printing LIS
vector<int> insertedat;

int lis(vector<int> &arr) {
   vector<int> temp;
   for (int i = 0; i < arr.size(); ++i) {
      if (temp.empty() or temp.back() < arr[i]) {
         temp.push_back(arr[i]);
         insertedat[i] = temp.size();
      } else {
         auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
         *it = arr[i];
         insertedat[i] = it - temp.begin() + 1;
      }
   }
   return temp.size();
}

void solve()
{
   int n;
   cin >> n;
   vector<int> arr(n);
   insertedat.resize(n);
   for (int i = 0; i < n; ++i)
   {
      cin >> arr[i];
   }

   int curlen = lis(arr);
   vector<int> final_lis;
   for (int i = n - 1; i >= 0; --i)
   {
      if (insertedat[i] == curlen) {
         final_lis.push_back(arr[i]);
         curlen--;
      }
   }

   reverse(final_lis.begin(), final_lis.end());

   for (auto it : final_lis) {
      cout << it << " ";
   }
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
