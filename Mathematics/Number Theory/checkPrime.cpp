#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

bool is_prime(long long x)
{
    for (long long i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    blaze;
    long long x;
    cin >> x;
    cout << is_prime(x) << endl;
    return 0;
}