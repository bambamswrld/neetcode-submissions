class Solution {
public:
    bool isAnagram(string s, string t) {
        std::array<int, 26> count = {0};
        auto sLen = s.size();
        auto tLen = t.size();
        
        if(sLen != tLen)
            return false;

        for(auto i = 0; i < sLen; i++)
        {
            auto c = s[i];
            auto d = t[i];
            count[c - 'a']++;
            count[d - 'a']--;
        }

        for(auto i = 0; i < 26; i++)
        {
            if(count[i] != 0)
                return false;
        } 

        return true;
    }
};
