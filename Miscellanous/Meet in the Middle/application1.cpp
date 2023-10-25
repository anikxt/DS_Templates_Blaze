#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
Given N rods with their lengths in array Arr[].
Can you use all the rods to combine them into bigger rods and form a square?

Observation:
1. On same side, order does not matter
2. Square we form has side length = total/4

Time Complexity: O((4^N/2)*N)

PseudoCode:
N, Arr = {}
Arr1,Arr2 = Split_In_Almost_Half(Arr);

// Possible Quadruplets from first half elements
Pos1 = generate(Arr1,0,0,0,0,0);

// Possible Quadruplets from second half elements
Pos2 = generate(Arr2,0,0,0,0,0);

// What happens when tot is not divisible by 4?
X = tot/4;

for (a,b,c,d) in Pos1:
    if({X - a, X-b, X - c, X - d} in Pos2):
        return 1
return 0
*/

int main() {
    blaze;

    return 0;
}