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

/* Whenever you have a scarce resource that you want to use in the smartest way possible,
you’re talking about a knapsack problem. */

int knapsack(int *size, int *value, int n, int Capacity)
{
    // subproblem solutions (indexed from 0)
    int a[n + 1][Capacity + 1];
    // base case (i = 0)
    for (int c = 0; c <= Capacity; ++c)
    {
        a[0][c] = 0;
    }
    // systematically solve all subproblems
    for (int i = 1; i <= n; ++i)
    {
        for (int c = 0; c <= Capacity; ++c)
        {
            if (size[i] > c)
            {
                a[i][c] = a[i - 1][c];
            }
            else
            {
                a[i][c] = max(a[i - 1][c], a[i - 1][c - size[i]] + value[i]);
            }
        }
    }
    return a[n][c]; // solution to largest subproblem
}

// knapsack reconstruction

vector<int> knapsackReconstruction(int *size, int *value, int n, int Capacity)
{
    vector<int> Solution; // items in an optimal solution
    int c = Capacity;     // remaining capacity
    int a[n + 1][Capacity + 1];
    for (int i = n; i >= 1; i--)
    {
        if (size[i] <= c and a[i - 1][c - size[i]] + value[i] >= a[i - 1][c])
        {
            Solution.push_back(i); // Case 2 wins, include i
            c = c - size[i];       // reserve space for it
        }
        // else skip i, capacity stays the same
    }

    return Solution;
}

int main()
{
    blaze;
#ifndef ONLINE_JUDGE
    freopen("/home/blaze/Desktop/Ember/input.txt", "r", stdin);
    freopen("/home/blaze/Desktop/Ember/output.txt", "w", stdout);
#endif

    return 0;
}
