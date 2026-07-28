class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> map;
        int res = 0, maxi = 0;
        for(auto& num : nums)
        {
            map[num]++;    
            if(map[num] > maxi)
            {
                res = num;
                maxi = map[num];
            }
        }
        return res;
    }
};