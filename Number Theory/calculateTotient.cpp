#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

vector<long long> TotientFunction(long long n)
{
    vector<long long> is_prime(n + 1, 1);

    is_prime[0] = 0, is_prime[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (long long j = 1LL * i * i; j <= n; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }

    vector<long long> phi(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        phi[i] = i;
    }

    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i; j <= n; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }

    return phi;
}

int main()
{
    blaze;
    long long n;
    cin >> n;
    vector<long long> phi = TotientFunction(n);

    for (int i = 1; i <= n; ++i)
    {
        cout << phi[i] << " ";
    }
    cout << endl;
    return 0;
}