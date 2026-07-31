class Solution 
{
public:
    static bool canConstruct(std::string ransomNote, std::string magazine) 
    {
        int letterCounts[26] = {0};
        for (int i = 0; i < magazine.length(); ++i) 
            letterCounts[magazine[i] - 'a']++;
        
        for (int i = 0; i < ransomNote.length(); ++i) 
        {
            int index = ransomNote[i] - 'a';
            if (--letterCounts[index] < 0) 
                return (false);
        }
        return (true);
    }
};