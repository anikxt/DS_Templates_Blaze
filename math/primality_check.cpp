#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fab(a, b, i) for (int i = a; i <= b; ++i)
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

void primeCheck(int n)
{
    if (n <= 1)
    {
        cout << "Not Prime" << endl;
        return;
    }
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            cout << "Not Prime" << endl;
            return;
        }
    }
    cout << "Prime" << endl;
}

int main()
{
    blaze;
    int n;
    cin >> n;
    primeCheck(n);
    return 0;
}

/* 

if a = b => a^2 = x => a = sqrt(x)
if a < b => a < sqrt(x), b > sqrt(x)
if b < a => b < sqrt(x), a > sqrt(x)

*/

// Time Complexity => O(nsqrtn)