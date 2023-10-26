#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/**
   works in armotized O(n) TC
**/

struct manacher {
   vector<int> p;

   void run_manacher(string s) {
      int n = s.size();
      p.assign(n, 1);
      // left and right pointers of a palindrome
      int l = 1, r = 1;
      for (int i = 1; i < n; ++i)
      {
         // bounding box optimisation
         p[i] = max(0, min(r - i, p[l + r - i]));
         while (i + p[i] < n and i - p[i] >= 0 and s[i + p[i]] == s[i - p[i]]) {
            p[i]++;
         }

         if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
         }
      }

      for (auto v : p) {
         cout << v << " ";
      }
      cout << endl;
   }


   void build(string s) {
      string t;
      for (auto v : s) {
         t += string("#") + v;
      }
      run_manacher(t + '#');
   }

   /**
      abbabba => #a#b#b#a#b#b#a#
      cen = 1, odd = 1 => a |b| babba  = 1 (b)
      cen = 1, odd = 0 => ab | babba  = 4 (abba)
   **/
   int getLongest(int cen, bool odd) {
      int pos = 2 * cen + 1 + (!odd);
      return p[pos] - 1;
   }

   bool checkPalin(int l, int r) {
      if ((r - l + 1) <= getLongest((l + r) / 2, l % 2 == r % 2)) {
         return 1;
      } else {
         return 0;
      }
   }
} m;

void solve()
{
   string s = "babbabbabc";
   m.build(s);
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