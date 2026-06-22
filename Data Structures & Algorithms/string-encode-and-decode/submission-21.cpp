class Solution {
public:

    string encode(vector<string>& strs) {
        std::string res = "";
        for(string s : strs)
        {
            res += std::to_string(s.size()) + '#' + s;
        }

        return res;
    }

    vector<string> decode(string s) {
        int n = s.size();
        std::vector<std::string> res;
        int i = 0;
        while(i < n)
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
