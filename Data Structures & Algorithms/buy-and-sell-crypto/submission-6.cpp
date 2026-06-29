class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int res = 0;

        while (r < prices.size())
        {
            int diff = prices[r] - prices[l];
            if (diff <= 0)
            {
                l = r;
            }
            else
            {
                if (diff > res)
                {
                    res = diff;
                }
            }
            r++;

        }

        return res;
    }
};
