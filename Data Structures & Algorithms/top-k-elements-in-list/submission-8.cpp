class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        
        // [num, freq]
        for(const auto& n : nums)
        {
            count[n]++;
        }
        
        std::vector<std::vector<int>> freq(nums.size() + 1);

        for(const auto& entry : count)
        {
            freq[entry.second].push_back(entry.first);
        }

        std::vector<int> result;

        for(int i = freq.size() - 1; i > 0; --i)
        {
            for(int n : freq[i])
            {
                result.push_back(n);
                if(result.size() == k)
                {
                    return result;
                }
            }
        }

        return result;
    }
};
