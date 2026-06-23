class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;

        for (auto& s : strs) {
            std::vector<int> count(26, 0);

            for (char c : s) {
                count[c - 'a']++;
            }

            string key = "";

            for (int i = 0; i < 26; i++) {
                key += ',' + std::to_string(count[i]);
            }

            map[key].push_back(s);
        }

        std::vector<std::vector<string>> res;

        for (auto& m : map) {
            res.push_back(m.second);
        }

        return res;
    }
};
