class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> count;
        int l = 0, maxf = 0, res = 0;

        for(int r = 0; r < s.size(); r++)
        {
            count[s[r]]++;
            maxf = std::max(maxf, count[s[r]]);

            while((r - l + 1) - maxf > k)
            {
                count[s[l]]--;
                l++;
            }

            res = std::max(res, r - l + 1);
        }
        return res;
    }
};