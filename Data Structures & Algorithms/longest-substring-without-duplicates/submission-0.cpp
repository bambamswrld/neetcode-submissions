class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) { return 0; }

        int l = 0;
        int r = 0;
        int res = 0;
        std::unordered_set<char> seen;

        while(r < s.size())
        {
            while(seen.count(s[r]))
            {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
