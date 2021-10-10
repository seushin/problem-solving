/*
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/
 */
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = left & right;

        for (int n = left; n < right; ++n)
        {
            res &= n;
            if (res == 0)
                return res;
        }
        return res;
    }
};
