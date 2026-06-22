class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int profit = 0;

        if(n == 1)
        {
            return 0;
        }

        for(int i = 1; i < n; i++)
        {
            int currPrice = prices[i];
            if(currPrice < buy)
            {
                buy = currPrice;
            }

            if((currPrice - buy) > profit)
            {
                profit = currPrice - buy;
            }
        }

        return profit;
    }
};
