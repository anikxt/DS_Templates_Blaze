#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fab(a, b, i) for (int i = a; i < b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define f first
#define se second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
//=======================
const int N = 2e6 + 13, M = N;
//=======================
int a[N];
int c, k, m, n, t, x, y;
//=======================

void merge(int A[], int L[], int nL, int R[], int nR)
{
  int i = 0, j = 0, k = 0;
  while (i < nL and j < nR)
  {
    if (L[i] <= R[j])
      A[k++] = L[i++];
    else
      A[k++] = R[j++];
  }
  while (i < nL)
  {
    A[k++] = L[i++];
  }
  while (j < nR)
  {
    A[k++] = R[j++];
  }
}

void mergeSort(int A[], int n)
{
  if (n < 2) // base condition
    return;
  int mid = n / 2;
  int nL = mid, nR = n - mid;
  int left[nL], right[nR];
  fab(0, mid, i)
  {
    left[i] = A[i];
  }
  fab(mid, n, i)
  {
    right[i - mid] = A[i];
  }
  mergeSort(left, nL);           // Recursive call
  mergeSort(right, nR);          // Recursive call
  merge(A, left, nL, right, nR); // Merge Sorted halves
}

int main()
{
  blaze;
  int a[] = {2, 7, 4, 1, 5, 3};
  int n = sizeof(a) / sizeof(a[0]);
  mergeSort(a, n);
  fab(0, n, i)
  {
    cout << a[i] << " ";
  }
  return 0;
}

/* Analysis of Merge Sort

1) Divide and Conquer
2) Recursive
3) Stable (relative order same as original list)
4) Not In-Place -> theta(n) Space Complexity
5) theta(nlogn) Time Complexity 

*/