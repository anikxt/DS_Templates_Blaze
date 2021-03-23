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

// Nearest Smaller Elements

/* the problem of finding for each array element the
nearest smaller element, i.e., the first smaller element that precedes the
element in the array. It is possible that no such element exists, in which case
the algorithm should report this. */

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  int a[n];
  fo(i, n) { cin >> a[i]; }
  vi v;
  stack<int> s;
  s.push(a[0]);
  int i = 1;
  while (i < n) {
    if (a[i] > s.top()) {
      s.push(a[i]);
      i++;
    } else {
      s.pop();
    }
  }
  if (s.empty()) {
    co << "true" << endl;
  } else {
    co << "false" << endl;
  }

  return 0;
}
