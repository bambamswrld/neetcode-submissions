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
        int i = 0;

        while(i < s.size())
        {
            int j = i;
            while(s[j] != '#')
            {
                j++;
            }
            int length = std::stoi(s.substr(i,j - i));
            res.push_back(s.substr(j + 1, length));
            i = j + 1+ length;
        }

        return res;
    }
};
