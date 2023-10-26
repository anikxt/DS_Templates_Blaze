#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Coordinate Compression

/*

N <= 1e5 arr

Query -
1 X - toggle X
2 K - No. of elements in set <= K

*/

#define int long long
struct Coordinate_Compress {
   map<int, int> compVal;
   vector<int> rev;
   int cnt;

   void add(int x) {
      compVal[x];
   }

   void build() {
      cnt = 0;
      for (auto &v : compVal) {
         rev.emplace_back(v.first);
         v.second = cnt++;
      }
   }

   inline int getComp(int x) {
      return compVal[x];
   }

   inline int getOrig(int x) {
      return rev[x];
   }

   int getPrev(int x) {
      auto it = compVal.upper_bound(x); //>
      it--; // logic dependent
      return it.second;
   }

   int getNext(int x) {
      auto it = compVal.lower_bound(x); //>=
      return it.second;
   }
} CMP;

void solve()
{
   vector<int> arr = {1, 3, 5, 4, 5, 2, 3, 1, 1000000};
   for (auto v : arr) {
      CMP.add(v);
   }

   // CMP.add(-MOD * MOD);
   // CMP.add(MOD * MOD);

   for (auto it : CMP.compVal) {
      cout << it.second << " ";
   }
   cout << endl;

   CMP.build();

   for (auto it : CMP.compVal) {
      cout << it.second << " ";
   }
   cout << endl;

   cout << CMP.getNext(5) << endl;
   cout << CMP.getNext(6) << endl;
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