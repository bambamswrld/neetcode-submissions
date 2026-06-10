class Solution {
public:
    bool isAnagram(string s, string t) {
        constexpr int size = 26;
        array<int,size> count;
        auto sLen = s.size();
        auto tLen = t.size();
        auto cLen = 26;

        if(sLen != tLen)
        {
            return false;
        }

        for(int i = 0; i < sLen; i++)
        {
            count[s.at(i) - 'a']++;
            count[t.at(i) - 'a']--;
        }

        for(int i = 0; i < cLen; i++)
        {
            if(count[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};
