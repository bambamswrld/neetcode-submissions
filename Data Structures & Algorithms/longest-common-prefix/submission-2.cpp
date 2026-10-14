class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string prefix = strs[0];

        for (auto i = 1; i < strs.size(); i++)
        {
            int j = 0;
            while (j < std::min(prefix.size(), strs[i].size()))
            {
                if (strs[i][j] != prefix[j])
                    break;
                
                j++;
            }
            prefix = prefix.substr(0, j);
        }

        return prefix;
    }
};