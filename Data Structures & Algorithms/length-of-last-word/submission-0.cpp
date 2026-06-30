class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), r = n - 1, count = 0;

        while(!isalnum(s[r]))
        {
            r--;
        }

        while(isalnum(s[r]))
        {
            count++;
            r--;
        }

        return count;
    }
};