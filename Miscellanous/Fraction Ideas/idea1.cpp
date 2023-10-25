#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
#pair (i, j) belongs to [0, N-1]
such that,
1) i < j
2) A[i]*j = A[j]*i
*/

#define int long long
int gcd(int a, int b) {
    if (a == 0 or b == 0)return a + b;
    return gcd(b, a % b);
}

pair<int, int> get_red_frac(int a, int b) {
    if (a == 0 and b == 0)return make_pair(0, 0);
    if (a == 0)return make_pair(0, 1);
    if (b == 0)return make_pair(1, 0);
    int x = gcd(a, b);
    return make_pair(a / x, b / x);
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    map<pair<int, int>, int> mp;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        ans += mp[get_red_frac(arr[i], i)];
        mp[get_red_frac(arr[i], i)]++;
    }

    cout << ans << endl;
}
#undef int

int main() {
    blaze;
    solve();
    return 0;
}