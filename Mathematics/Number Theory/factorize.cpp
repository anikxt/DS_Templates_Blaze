#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

#define int long long

vector<pair<int, int>> Factors(int x)
{
    vector<pair<int, int>> ans;

    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                cnt++;
                x /= i;
            }
            ans.push_back({i, cnt});
        }
    }
    if (x > 1)
    {
        ans.push_back({x, 1});
    }
    return ans;
}

int main()
{
    blaze;
    int x;
    cin >> x;
    vector<pair<int, int>> ans = Factors(x);

    for (auto i : ans)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}