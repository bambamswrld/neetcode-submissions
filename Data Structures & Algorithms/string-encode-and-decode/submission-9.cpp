class Solution {
public:

    string encode(vector<string>& strs) {
        std::string res = "";
        for(auto& s : strs)
        {
            res += std::to_string(s.size()) + '#' + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        std::vector<std::string> res;
        const int sLen = s.size();
        for(int i = 0; i < sLen; )
        {
            int j = i;
            while(s[j] != '#')
            {
                j++;
            }
            int length = std::stoi(s.substr(i, j));
            res.push_back(s.substr(j + 1, length));
            i = j + 1 + length;
        }
        return res;
    }
};
