#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

vector<long long> SegmentedSieve(long long a, long long b)
{
    // generate all primes up to sqrt(b)
    long long lim = sqrt(b);
    vector<long long> is_prime(b + 1, 1);
    is_prime[0] = 0, is_prime[1] = 0;

    for (int i = 2; i <= lim; ++i)
    {
        if (is_prime[i])
        {
            for (long long j = 1LL * i * i; j <= lim; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }

    vector<long long> primes;

    for (int i = 2; i <= lim; ++i)
    {
        if (is_prime[i])
            primes.push_back(i);
    }

    for (int i = 0; i < primes.size(); ++i)
    {
        long long prime = primes[i];
        long long curMul = ((a + prime - 1) / prime) * prime; // multiple of prime which is >= a

        while (curMul <= b)
        {
            if (curMul != prime)
            {
                is_prime[curMul] = 0;
            }
            curMul += prime;
        }
    }

    return is_prime;
}

int main()
{
    blaze;
    long long a, b;
    cin >> a >> b;
    vector<long long> is_prime = SegmentedSieve(a, b);

    for (int i = a; i <= b; ++i)
    {
        cout << i << " " << is_prime[i] << endl;
    }
    return 0;
}