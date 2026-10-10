class Solution {
public:
    int countSubstrings(string s) {
        int l = 0, r = 0, n = s.size();
        auto count = 0;

        for (auto i = 0; i < n; i++)
        {
            l = i;
            r = i;

            while (l >= 0 && r < n && s[l] == s[r])
            {
                count++;
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            
            while (l >= 0 && r < n && s[l] == s[r])
            {
                count++;
                l--;
                r++;
            }            
        }
        return count;       
    }
};
