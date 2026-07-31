class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::vector<int> count(26, 0);

        for (int i = 0; i < ransomNote.length(); i++)
        {
            char c = ransomNote[i];
            count[c - 'a']++;
        }

        for (int i = 0; i < magazine.length(); i++)
        {
            char c = magazine[i];
            count[c - 'a']--;
        }

        for(int i = 0; i < count.size(); i++)
        {
            if (count[i] > 0)
                return false;
        }

        return true;
    }
};