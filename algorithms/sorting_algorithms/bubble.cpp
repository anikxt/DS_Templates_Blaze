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

void bubbleSort(int a[], int n)
{
    fab(0, n - 1, i)
    {
        int f = 0;
        fab(0, n - i - 1, j)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                f = 1;
            }
        }
        if (!f)
            break;
    }
    fab(0, n, i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    blaze;
    int a[6] = {2, 7, 4, 1, 5, 3};
    int n = sizeof(a) / sizeof(a[0]);
    bubbleSort(a, n);
    return 0;
}

// Best Case - O(n)
// Average Case - O(n^2)
// Worst Case - O(n^2)