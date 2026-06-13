class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, vector<string>> map;

        for(const auto& s : strs)
        {
            vector<int> count(26,0);            
        
            for(char c : s)
            {
                count[c - 'a']++;
            }

            string key = "";
            
            for(int i = 0; i < 26; i++)
            {
                key += ',' + to_string(count[i]);
            }
            map[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto& [s , lst] : map)
        {
            result.push_back(lst);
        }      
        return result;
    }
};
