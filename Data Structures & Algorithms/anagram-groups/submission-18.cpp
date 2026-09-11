class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        std::vector<std::vector<std::string>> res;

        for (auto str : strs)
        {
            std::vector<char> count(26, 0);

            for (char c : str)
            {
                count[c - 'a']++;
            }

            std::string key = "";

            for (int i = 0; i < 26; i++)
            {
                key += ',' + std::to_string(count[i]);
            }

            map[key].push_back(str);
        }

        for (auto entry : map)
        {
            res.push_back(entry.second);
        }

        return res;
    }
};
