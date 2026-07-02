class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> res1, res2;
        std::unordered_set<int> num1Set(nums1.begin(), nums1.end());
        std::unordered_set<int> num2Set(nums2.begin(), nums2.end());

        for(auto& num : num1Set)
        {
            if(num2Set.find(num) == num2Set.end())
            {
                res1.push_back(num);
            }
        }

        for(auto& num : num2Set)
        {
            if(num1Set.find(num) == num1Set.end())
            {
                res2.push_back(num);
            }
        }

        return {res1, res2};
    }
};