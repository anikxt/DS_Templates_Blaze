#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// find the prime factorization of all number from 1 - 10^6

vector<long long> FastFactor(int n)
{
    vector<long long> sp(n + 1, 0);
    for (int i = 2; i <= n; ++i)
    {
        sp[i] = i;
    }

    for (int i = 2; i <= n; ++i)
    {
        if (sp[i] == i)
        {   // that means its a prime
            for (int j = 2 * i; j <= n; j += i)
            {
                if (sp[j] == j)
                {
                    sp[j] = i;
                }
            }
        }
    }

    // factorizing a number using the sp array
    vector<long long> ans;
    while (n > 1)
    {
        ans.push_back(sp[n]);
        n /= sp[n];
    }
    return ans;
}

int main()
{
    blaze;
    int n;
    cin >> n;
    vector<long long> ans = FastFactor(n);

    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}