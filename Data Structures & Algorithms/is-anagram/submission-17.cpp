class Solution {
   public:
    bool isAnagram(string s, string t) {
        std::array<int, 26> counts;
        int sLen = s.size();
        int tLen = t.size();
        int cLen = 26;

        if (sLen != tLen) {
            return false;
        }

        for (int i = 0; i < sLen; i++) {
            counts[s.at(i) - 'a']++;
            counts[t.at(i) - 'a']--;
        }

        for (int i = 0; i < cLen; i++) {
            if (counts[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
