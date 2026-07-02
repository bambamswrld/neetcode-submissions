class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        std::vector<int> count(26, INT_MAX);

        for(auto& w : words)
        {
            std::vector<int> curCount(26, 0);
            for(auto& c : w)
            {
                curCount[c - 'a']++;
            }

            for(int i = 0; i < 26; i++)
            {
                count[i] = min(count[i], curCount[i]);
            }
        }

        std::vector<string> res;

        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < count[i]; j++)
            {
                res.push_back(string(1, i + 'a'));
            }
        }

        return res;
    }
};