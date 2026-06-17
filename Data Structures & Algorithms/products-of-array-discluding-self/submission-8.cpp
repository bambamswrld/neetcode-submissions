class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        std::vector<int> pre(n);
        std::vector<int> post(n);
        std::vector<int> res(n); 
        
        pre[0] = 1;
        post[n - 1] = 1;
        
        for(i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] * nums[i - 1];
        }

        for(i = n - 2; i >= 0; i--)
        {
            post[i] = post[i + 1] * nums[i + 1];
        }
        
        for(i = 0; i < n; i++)
        {
            res[i] = pre[i] * post[i];
        }

        return res;
    }
};
