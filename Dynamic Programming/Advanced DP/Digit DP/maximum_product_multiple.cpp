#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define int long long
string L, R;
int k, len;
int dp[20][2][2][(1 << 10)][100][2];
int num[20][2][2][(1 << 10)][100][2];

// https://www.codechef.com/problems/MPRODMUL

// Mask represents the digits that are not satisfied till now in the places seen till now
int rec(int level, int tlo, int thi, int mask, int rem, int start) {
    if (level == len) {
        //check for mask has only one set bit one and remainder is 0
        return (rem == 0 and __builtin_popcountll(mask) == 1);
    }

    if (dp[level][tlo][thi][mask][rem][start] != -1)
        return dp[level][tlo][thi][mask][rem][start];

    int ans = 0;
    int lo = 0, hi = 9;
    if (tlo == 1)lo = L[level] - '0';
    if (thi == 1)hi = R[level] - '0';

    for (int i = lo; i <= hi; i++) {
        int ntlo = tlo, nthi = thi;

        if (i != lo)ntlo = 0;
        if (i != hi)nthi = 0;

        int nmask = mask;
        int nrem = rem;
        int nstart = start;

        if (nstart == 1) {
            if (i == 0)
                continue;

            for (int j = 2 * i; j <= 9 and i != 0; j += i)
            {
                if (nmask & (1 << j)) {
                    // check if there is any bit set divisible by this i
                    if (j % i == 0) {
                        // then set its bit equal to zero
                        nmask ^= (1 << j);
                    }
                }
            }
            // set this bit
            nmask |= (1 << i);
            nrem = (10 * rem + i) % k;
        }
        else {
            if (i != 0) {
                nmask |= (1 << i);
                nrem = (10 * nrem + i) % k;
                nstart = 1;
            }
        }

        int cur_digit = (i == 0 ? 1 : i);
        int temp = rec(level + 1, ntlo, nthi, nmask, nrem, nstart);
        if (temp * cur_digit > ans) {
            ans = temp * cur_digit;
            num[level][tlo][thi][mask][rem][start] = i;
        }
    }

    return dp[level][tlo][thi][mask][rem][start] = ans;
}

string num_str;
void printset(int level, int tlo, int thi, int mask, int rem, int start) {
    if (level == len)
        return;

    int ans = rec(level, tlo, thi, mask, rem, start);
    int lo = 0, hi = 9;
    if (tlo == 1)lo = L[level] - '0';
    if (thi == 1)hi = R[level] - '0';

    int cur_digit = num[level][tlo][thi][mask][rem][start];

    num_str += (cur_digit + '0');

    int ntlo = tlo, nthi = thi;

    if (cur_digit != lo)ntlo = 0;
    if (cur_digit != hi)nthi = 0;

    int nmask = mask;
    int nrem = rem;
    int nstart = start;

    if (cur_digit != 0) {
        for (int j = 2 * cur_digit; j <= 9; j += cur_digit)
        {
            if (nmask & (1 << j)) {
                // check if there is any bit set divisible by this current digit
                if (j % cur_digit == 0) {
                    // then set its bit equal to zero
                    nmask ^= (1 << j);
                }
            }
        }
        // set this bit
        nmask |= (1 << cur_digit);
        nrem = (10 * rem + cur_digit) % k;
        nstart = (start | (cur_digit > 0));
    }

    printset(level + 1, ntlo, nthi, nmask, nrem, nstart);
}

void solve() {
    cin >> L >> R >> k;
    int cnt = R.size() - L.size();
    string temp = "";
    while (cnt--) {
        temp += '0';
    }
    L = temp + L;
    len = R.size();

    memset(dp, -1, sizeof(dp));
    int prod = rec(0, 1, 1, 0, 0, 0);

    if (prod != 0) {
        cout << prod << " ";
        num_str = "";
        printset(0, 1, 1, 0, 0, 0);
        reverse(num_str.begin(), num_str.end());
        while (!num_str.empty() and num_str.back() == '0') {
            num_str.pop_back();
        }
        reverse(num_str.begin(), num_str.end());
        cout << num_str << endl;
    }
    else {
        cout << -1 << endl;
    }
}
#undef int

int main()
{
    blaze;
    int _t = 1;
    cin >> _t;
    while (_t--) {
        solve();
    }
    return 0;
}
