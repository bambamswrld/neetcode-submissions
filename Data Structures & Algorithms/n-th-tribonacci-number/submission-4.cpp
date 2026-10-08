class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1)
            return n;
        if (n == 2)
            return 1;

        auto t0 = 0, t1 = 1, t2 = 1;

        for (auto i = 3; i <= n; i++)
        {
            auto nVal = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = nVal;
        }

        return t2;
    }
};