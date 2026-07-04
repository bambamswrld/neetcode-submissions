class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> res;
        int m = nums.size();

        for(int i = 0; i <= m - k; i++)
        {
            int maxf = nums[i];
            int r = i + 1;
            while(r < i + k)
            {
                maxf = std::max(maxf, nums[r]);
                r++;
            }
            res.push_back(maxf);
        }
        
        return res;
    }
};
