#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; ++i)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define elif else if
#define co cout
#define endl '\n'
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================
const int MOD = 1'000'000'007;
const int N = 2e6 + 13, M = N;
//=======================
vi g[N];
int a[N];
int c, k, m, n, t, x, y;
//=======================

// Two Pointers - Subarray Sum

/* consider a problem where we are given an array of n positive
integers and a target sum x , and we want to find a subarray whose sum is x or
report that there is no such subarray. */

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> x;
  int a[n];
  fo(i, n) { cin >> a[i]; }
  int i = 0, j = 0, sum = a[0];
  while (j < n) {
    if (sum > x) {
      sum -= a[i];
      i++;
      if (sum == x) {
        break;
      }
    } else if (sum < x) {
      j++;
      sum += a[j];
      if (sum == x) {
        break;
      }
    }
  }
  deb(i);
  deb(j);
  return 0;
}
