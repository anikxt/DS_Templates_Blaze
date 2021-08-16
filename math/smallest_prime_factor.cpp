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
int c, k, m, t, x, y;
//=======================

const int n = 1e6;
vector<int> spf(n + 1, -1);

void solve(int n)
{
    for (int i = 2; i <= n; ++i)
    {
        if (spf[i] == -1)
        {
            for (int j = i; j <= n; j += i)
            {
                if (spf[j] == -1)
                    spf[j] = i;
            }
        }
    }
    return;
}

int main()
{
    blaze;
#ifndef ONLINE_JUDGE
    freopen("/home/blaze/Desktop/dsa_cp/input.txt", "r", stdin);
    freopen("/home/blaze/Desktop/dsa_cp/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    solve(n);
    return 0;
}