class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};

        for (auto i = 0; i < ransomNote.length(); i++)
        {
            auto c = ransomNote[i];
            count[c - 'a']++;
        }

        for (auto i = 0; i < magazine.length(); i++)
        {
            auto c = magazine[i];
            count[c - 'a']--;
        }

        for(auto i = 0; i < 26; i++)
        {
            if (count[i] > 0)
                return false;
        }

        return true;
    }
};