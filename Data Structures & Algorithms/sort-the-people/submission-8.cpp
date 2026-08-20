class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        std::unordered_map<int, string> map;
        std::vector<string> res;
        
        for (int i = 0; i < heights.size(); i++)
        {
            map[heights[i]] = names[i];
        }

        std::sort(heights.begin(), heights.end());

        for (int i = heights.size() - 1; i >= 0; i--)
        {
            res.push_back(map[heights[i]]);
        }

        return res;
    }
};