#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
find area covered by atleast k segments

N
Li Ri Zi

*X -> find max Z value active there

X Y -> find Yth value active at X

Hint:
[L -> start, query
(L -> query, start
R] -> query, end
r) -> end, query
*/

int main() {
    blaze;
    int n, q;
    cin >> n >> q;

    vector<pair<int, pair<int, int>>> events;
    for (int i = 0; i < n; ++i)
    {
        int l, r, z;
        cin >> l >> r >> z;
        events.push_back({l, {0, z}});
        events.push_back({r, {2, z}});
    }

    for (int i = 0; i < q; ++i)
    {
        int x;
        cin >> x;
        events.push_back({x, {1, i}});
    }
    sort(events.begin(), events.end());

    // data structure to maintain with sweepline
    multiset<int> mt;
    int ans[q];

    for (int i = 0; i < n; ++i)
    {
        // handle the event
        if (events[i].second.first == 0) {
            // start
            mt.insert(events[i].second.second);
        } else if (events[i].second.first == 2) {
            // end
            mt.erase(mt.find(events[i].second.second));
        } else {
            // query
            if (!mt.empty()) {
                ans[events[i].second.second] = *mt.rbegin();
            } else {
                ans[events[i].second.second] = -1;
            }
        }

        // add the current segments contribution
    }

    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << endl;
    }
    return 0;
}