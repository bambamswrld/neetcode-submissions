class Solution {
    public boolean isAnagram(String s, String t) {
        int sLen = s.length();
        int tLen = t.length();
        
        if(sLen != tLen)
        {
            return false;
        }

        int[] count = new int[26];
        int cLen = count.length;

        for(int i = 0; i < sLen; i++)
        {
            char c = s.charAt(i);
            count[c - 'a']++;
        }

        for(int i = 0; i < tLen; i++)
        {
            char c = t.charAt(i);
            count[c - 'a']--;
        }

        for(int i = 0; i < cLen; i++)
        {
            if(count[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
}