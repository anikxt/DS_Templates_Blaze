#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fab(a, b, i) for (int i = a; i < b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
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

// a recursive algorithm (without caching)

int recursiveWIS(int *a, int idx)
{
    if (idx < 0) // base case #1
        return 0;
    if (idx == 0) // base case #2
        return a[0];
    // recursion when n >= 2
    int s1 = recursiveWIS(a, idx - 1);
    int s2 = recursiveWIS(a, idx - 2);
    return max(s1, s2 + a[idx]);
}

// an iterative bottom-up implementation (includes caching)

int wisBottomUp(int *a, int n)
{
    int arr[n + 1]; // subproblem solutions
    arr[0] = 0;     // base case #1
    arr[1] = a[0];  // base case #2
    for (int i = 2; i <= n; ++i)
    {
        // use recurrence
        arr[i] = max(arr[i - 1], arr[i - 2] + a[i - 1]);
    }

    return arr[n]; // solution to largest subproblem
}

// WIS Reconstruction algorithm

vector<int> wisReconstruction(int *a, int n, int *arr)
{
    vector<int> v;
    int i = n;
    while (i >= 2)
    {
        if (arr[i - 1] >= arr[i - 2] + a[i - 1]) // case 1 wins
        {
            i = i - 1; // exclude Vi
        }
        else // case 2 wins
        {
            v.push_back(a[i - 1]);
            i = i - 2; // exclude Vi-1
        }
    }
    if (i == 1)
    {
        v.push_back(a[i - 1]);
    }

    return v;
}

int main()
{
    blaze;
#ifndef ONLINE_JUDGE
    freopen("/home/blaze/Desktop/Ember/input.txt", "r", stdin);
    freopen("/home/blaze/Desktop/Ember/output.txt", "w", stdout);
#endif
    int a[] = {1, 4, 5, 4};
    n = sizeof(a) / sizeof(a[0]);
    cout << recursiveWIS(a, n - 1) << endl;
    cout << wisBottomUp(a, n) << endl;
    return 0;
}