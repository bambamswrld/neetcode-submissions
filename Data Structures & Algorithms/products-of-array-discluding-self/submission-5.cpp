class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int len = nums.size();
        std::vector<int> pre(len);
        std::vector<int> post(len);
        std::vector<int> res(len);        
        int i = 0;
        
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

        for(i = 0; i < len; i++)
        {
            res[i] = pre[i] * post[i];
        }

        return res;
    }
};
