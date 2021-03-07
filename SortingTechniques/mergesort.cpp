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
int c, n, m, k, x, y;
//=======================

//Merging

void Merge(int a[], int low, int mid, int high)
{
  int i, j, k;
  int b[high + 1];
  i = low, j = mid + 1, k = low;
  while (i <= mid && j <= high)
  {
    if (a[i] < a[j])
    {
      b[k++] = a[i++];
    }
    else
    {
      b[k++] = a[j++];
    }
  }
  for (; i <= mid; ++i)
  {
    b[k++] = a[i];
  }
  for (; j <= high; ++j)
  {
    b[k++] = a[j];
  }
  for (int i = low; i <= high; ++i)
  {
    a[i] = b[i];
  }
}

// Iterative Merge Sort (two way merge sort)

void IMergeSort(int a[], int n)
{
  int p, i, low, mid, high;
  for (p = 2; p <= n; p *= 2) // this loop is for passes
  {
    for (i = 0; i + p - 1 < n; i += p)
    {
      low = i;
      high = i + p - 1;
      mid = low + (high - low) / 2;
      Merge(a, low, mid, high);
    }
  }
  if (p / 2 < n)
  {
    Merge(a, 0, p / 2 - 1, n - 1); // Merging the remaining elements (odd elements count or when the list size is not in the powers of 2)
  }
}

// Recursive Merge Sort (uses top-down approach)

void MergeSort(int a[], int low, int high)
{
  if (low < high)
  {
    int mid = low + (high - low) / 2;
    MergeSort(a, low, mid);
    MergeSort(a, mid + 1, high);
    Merge(a, low, mid, high);
  }
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  int a[n];
  fo(i, n)
  {
    cin >> a[i];
  }

  IMergeSort(a, n);
  fo(i, n)
  {
    co << a[i] << " ";
  }
  cout << endl;

  MergeSort(a, 0, n - 1);
  fo(i, n)
  {
    co << a[i] << " ";
  }
  return 0;
}
