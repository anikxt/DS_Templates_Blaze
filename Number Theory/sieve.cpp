#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

vector<long long> Sieve(long long n)
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
    return is_prime;
}

int main()
{
    blaze;
    long long n;
    cin >> n;
    vector<long long> is_prime = Sieve(n);

    for (int i = 0; i <= n; ++i)
    {
        cout << i << " " << is_prime[i] << endl;
    }
    return 0;
}