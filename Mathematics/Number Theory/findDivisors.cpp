#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

vector<long long> Divisors(long long x)
{
    vector<long long> ans;

    for (long long i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ans.push_back(i);
            if (i * i != x)
            {
                ans.push_back(x / i);
            }
        }
    }
    return ans;
}

int main()
{
    blaze;
    long long x;
    cin >> x;
    vector<long long> ans = Divisors(x);

    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}