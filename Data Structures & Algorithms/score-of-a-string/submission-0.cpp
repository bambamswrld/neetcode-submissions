class Solution {
public:
    int scoreOfString(string s) {
        int res = 0, n = s.size();

        for(int i = 0; i < n - 1; i++)
        {
            int j = i + 1;
            int aSum = s[j] - s[i];
            res += std::abs(aSum);
        }

        return res;
    }
};