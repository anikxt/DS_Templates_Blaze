#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
find area covered by atleast k segments

N
Li Ri
*/

int main() {
    blaze;
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> events;
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        events.push_back({l, 0});
        events.push_back({r, 1});
    }

    sort(events.begin(), events.end());
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < events.size(); ++i)
    {
        // handle the event
        if (events[i].second == 0) {
            cnt++;
        } else {
            cnt--;
        }

        // add the current segments contribution
        if ((i + 1) <events.size() and cnt >= k) {
            ans += events[i + 1].first - events[i].first;
        }
    }

    cout << ans << endl;
    return 0;
}