class Solution {
public:
    string longestPalindrome(string s) {
        int l = 0, r = 0, n = s.size();
        int resIdx = 0, resLen = 0;

        for (int i = 0; i < n; i++)
        {
            l = i;
            r = i;  

            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (r - l + 1 > resLen)
                {
                    resIdx = l;
                    resLen = r - l + 1;
                }

                l--;
                r++;
            }

            l = i;
            r = i + 1;
            
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (r - l + 1 > resLen)
                {
                    resIdx = l;
                    resLen = r - l + 1;
                }
                
                l--;
                r++;
            }
        }
        return s.substr(resIdx, resLen);
    }
};
