#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
using ll = long long int;
//=======================

// Calculate a^b mod 10^9+7

// 1011
// a*(a^2)*(a^8)

ll binary_exponentiation(ll a, ll b, int mod) // O(log b)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 2;
    }
    return res;
}

// a^-1 mod p = a^(p-2) mod p
// O(log p)

int main()
{
    blaze;
    int a, b;
    cin >> a >> b;
    // cin >> a;

    cout << binary_exponentiation(a, b, 1e9 + 7) << endl;

    // cout << binary_exponentiation(a, 1e7 + 7 - 2, 1e9 + 7) << endl;
    return 0;
}