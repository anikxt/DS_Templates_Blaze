#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
N
a1 a2 a3 ... an

if there exist a subset with (sum%N) == 0
print yes else -1

Pseduo Code 1: Count
mp[0] = 1;
long long ans = 0;

for (int i = 0; i < n; ++i)
{
    ans += mp[p[i]];
    mp[p[i]]++;
}

Pseduo Code 2: Find One
mp[0] = -1;

for (int i = 0; i < n; ++i)
{
    if(mp.find(p[i])){
        // solution in (mp[p[i]] + 1, i)
        break;
    }
    mp[p[i]] = i;
}

Pseduo Code 1: Find All
map<int, vector<int>> mp;
mp[0].push_back(-1);
ans = 0;

for (int i = 0; i < n; ++i)
{
    for(auto v: mp[p[i]]){
        // solution in (v + 1, i)
    }
    ans += mp[p[i]].size();
    mp[p[i]].push_back(i);
}
*/

int main() {
    blaze;

    return 0;
}