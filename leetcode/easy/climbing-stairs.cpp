class Solution {
public:
    int cache[46] = { 0 };

    int climbStairs(int n) {
        if (n <= 2)
            return n;

        int &res = cache[n];
        if (res != 0)
            return res;
        if (n - 1 >= 0)
            res += climbStairs(n - 1);
        if (n - 2 >= 0)
            res += climbStairs(n - 2);
        return res;
    }
};
