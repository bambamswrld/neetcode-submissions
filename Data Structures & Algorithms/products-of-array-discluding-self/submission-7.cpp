class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        std::vector<int> pre(len);
        std::vector<int> post(len);
        
        pre[0] = 1;
        post[len - 1] = 1;
        
        for(i = 1; i < len; i++)
        {
            pre[i] = pre[i - 1] * nums[i - 1];
        }

        for(i = len - 2; i >= 0; i--)
        {
            post[i] = post[i + 1] * nums[i + 1];
        }

        std::vector<int> res(len);        
        
        for(i = 0; i < len; i++)
        {
            res[i] = pre[i] * post[i];
        }

        return res;
    }
};
