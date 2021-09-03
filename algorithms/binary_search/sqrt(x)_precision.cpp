// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        // Find the last M such that M*M <= X.
        int left = 0, right = x;
        int ans = -1; // this -1 shouldn't be returned because we will find some M such that M*M <= x, e.g. M=0 is fine
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if((long long) mid * mid <= x) {
                ans = mid;
                left = mid + 1; // we're looking for the last element satisfying the condition
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
