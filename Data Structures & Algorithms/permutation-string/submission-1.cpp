class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) { return false; }
        std::vector<int> count(26, 0); 
        std::vector<int> window(26, 0);
        int m = s1.size();

        for(auto& c : s1)
        {
            count[c - 'a']++;
        }

        for(int i = 0; i < m; i++)
        {
            window[s2[i] - 'a']++;
            if(count == window) { return true; }
        }

        for(int r = m; r < s2.size(); r++)
        {
            window[s2[r] - 'a']++;
            window[s2[r - m] - 'a']--;

            if(count == window) { return true; }
        }

        return false;
    }
};
