class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> map;
        std::vector<std::vector<int>> freq(nums.size() + 1);
        std::vector<int> res;

        for (auto num : nums)
        {
            map[num]++;
        }

        for (auto entry : map)
        {
            freq[entry.second].push_back(entry.first);
        }

        for (int i = freq.size() - 1; i > 0; i--)
        {
            for (auto n : freq[i])
            {
                res.push_back(n);
                if (res.size() == k)
                    return res;
            }
        }

        return res;
    }
};
