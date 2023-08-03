#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

vector<long long> TotientFunction(long long n)
{
    vector<long long> phi(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        phi[i] = i;
    }

    for (int i = 2; i <= n; ++i)
    {
        if (phi[i] == i) {
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