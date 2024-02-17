#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl
#define pr(v) for(auto &x: v) cout << x << ' '; cout << '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/* stuff you should look for
   * "Keep your thought process clear!"
    * THINK FIRST!, THEN CODE!
    * List/write down the OBSERVATIONS and think in a DISCIPLINED way !
    * Observe/simulate the test cases properly
    * Re-read the question.
    * DON'T GET STUCK ON ONE APPROACH
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * comparitive(&&,||,==) execute first than bit operator(<<,>>,&,^,|).
    * do smth instead of nothing and stay organized
*/

/*
https://codeforces.com/contest/1300/problem/D

Code Explanation:

Initialization:
Define a type pii to represent pairs of coordinates (x, y).
Set a maximum size for the polygon's vertices.
Prepare variables for storing the center of symmetry and temporary coordinates.

Input:
Read the number of vertices from the input.
Read the coordinates of each vertex
and double their values (likely for precision).

Check for Odd Number of Vertices:
If the polygon has an odd number of vertices,
it cannot be centrally symmetric. Print "NO" and exit.

Calculate Potential Center of Symmetry:
Assume the first vertex and its opposite vertex (at index 1 + n / 2)
define a potential center of symmetry.

Verify Central Symmetry:
>> Iterate through half of the vertices:
   Calculate the midpoint between each vertex
   and its corresponding opposite vertex.
   If any midpoint doesn't match the assumed center,
   the polygon is not centrally symmetric. Print "NO" and exit.

Confirm Similarity:
If all midpoints match, the polygon is centrally symmetric
and thus similar to itself. Print "YES".
*/

/*
**Here's the explanation for why a polygon
  with an odd number of vertices cannot be centrally symmetric:**

**1. Pairing of Vertices:**

- Central symmetry requires vertices to exist in pairs,
  where each vertex has a corresponding vertex at an equal distance
  from the center of symmetry.
- In polygons with an even number of vertices, this pairing is possible.
  Each vertex can be matched with its "opposite" vertex across the center.
- However, in polygons with an odd number of vertices,
  there's always one vertex left unpaired.
  It cannot have a corresponding vertex at the same distance from the center,
  as that would create an even number of vertices.

**2. Rotational Invariance:**

- Central symmetry involves a 180-degree rotation around the center.
- When a polygon with an odd number of vertices is rotated 180 degrees,
  the unpaired vertex ends up on the opposite side of the polygon,
  not overlapping with its original position.
  This violates the requirement of rotational invariance.

**3. Line Segments and the Center:**

- In a centrally symmetric polygon,
  any line segment connecting a vertex to its corresponding vertex
  must pass through the center of symmetry.
- In a polygon with an odd number of vertices,
  there's no way to draw such line segments for all vertices
  while maintaining a single center of symmetry.

**Visual Example:**

- Consider a triangle (3 vertices).
  If you try to find a center of symmetry,
  you'll realize that no matter where you place it,
  one vertex always ends up on the opposite side of the triangle
  after a 180-degree rotation.
- Contrast this with a square (4 vertices).
  The center of the square acts as a clear center of symmetry,
  and each vertex aligns with its corresponding vertex after rotation.

**Conclusion:**

- The fundamental concept of central symmetry,
  involving paired vertices and 180-degree rotational invariance,
  inherently requires an even number of vertices for its existence.
- Therefore, a polygon with an odd number of vertices cannot possess
  central symmetry.

*/

#define int long long
const int N = 2e5 + 10, MOD = 1e9 + 7, INF = 1e18;
pair<int, int> a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].F >> a[i].S;
        a[i].F <<= 1;
        a[i].S <<= 1;
    }

    if (n & 1)
    {
        cout << "NO" << endl;
        return;
    }

    pair<int, int> ans, now;
    ans = {(a[1].F + a[1 + n / 2].F) >> 1, (a[1].S + a[1 + n / 2].S) >> 1};
    for (int i = 1; i <= n / 2; ++i)
    {
        now = {(a[i].F + a[i + n / 2].F) >> 1, (a[i].S + a[i + n / 2].S) >> 1};
        if (ans != now) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    return;
}
#undef int

int main()
{
    blaze;
    // int _t; cin >> _t; while (_t--)
    solve();
    return 0;
}