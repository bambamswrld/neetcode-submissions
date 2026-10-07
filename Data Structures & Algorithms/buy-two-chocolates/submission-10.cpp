class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        std::sort(prices.begin(), prices.end());
        int min1 = prices[0], min2 = prices[1];

        if (money - (min1 + min2) < 0)
            return money;
            
        return money - (min1 + min2);
    }
};