#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
N Points
(xi, yi)

Find a line that passes through maximum point

Input1:
2 2
3 3
3 3

Input2:
2 2
2 2
3 3
3 3
*/

#define int long long
int gcd(int a, int b) {
    if (a == 0 or b == 0)return a + b;
    return gcd(b, a % b);
}

pair<int, int> get_red_frac(int a, int b) {
    if (a == 0 and b == 0)return make_pair(0LL, 0LL);
    if (a == 0)return make_pair(0LL, 1LL);
    if (b == 0)return make_pair(1LL, 0LL);
    int neg = 1;
    if (a < 0) {neg *= -1, a *= -1;};
    if (b < 0) {neg *= -1, b *= -1;};
    int x = gcd(a, b);
    // we are normalizing if there's negative its gonna be in the numerator
    return make_pair(neg * a / x, b / x);
}

void solve() {
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int same = 0;
        // for every pivot point we create a map
        map<pair<int, int>, int> mp;
        for (int j = 0; j < n; ++j)
        {
            if (x[j] != x[i] or y[j] != y[i]) {
                mp[get_red_frac(y[i] - y[j], x[i] - x[j])]++;
            } else {
                same++;
            }
        }

        for (auto v : mp) {
            ans = max(ans, same + v.second);
        }
    }

    cout << ans << endl;
}
#undef int

int main() {
    blaze;
    solve();
    return 0;
}