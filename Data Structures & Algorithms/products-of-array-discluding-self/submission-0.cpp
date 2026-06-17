class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> res;
        int len = nums.size();
        
        for(int i = 0; i < len; i++)
        {
            int product = 1;
            for(int j = 0; j < len; j++)
            {
                if(j != i)
                {
                    product *= nums[j];
                }
            }
            res.push_back(product);
        }
        return res;
    }
};
