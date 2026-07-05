class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size() || t.empty()) { return ""; }

        std::unordered_map<char, int> countT;
        for(auto& c : t) { countT[c]++; }

        std::pair<int, int> res;
        int resLen = INT_MAX;

        for(int i = 0; i < s.length(); i++)
        {
            std::unordered_map<char, int> countS;
            
            for(int j = i; j < s.length(); j++)
            {
                countS[s[j]]++;
                bool flag = true;

                for(auto& [c, cnt] : countT)
                {
                    if(countS[c] < cnt)
                    {
                        flag = false;
                        break;
                    }
                }
            
                if(flag && (j - i + 1) < resLen)
                {
                    resLen = j - i + 1;
                    res = {i, j};
                }
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
