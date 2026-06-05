class Solution {
    public boolean isAnagram(String s, String t) {
        int sLen = s.length();
        int tLen = t.length();
        if(sLen != tLen)
        {
            return false;
        }

        int[] counts = new int[26];
        
        for(int i = 0; i < sLen;i++)
        {
            counts[s.charAt(i) - 'a']++;
            counts[t.charAt(i) - 'a']--;
        }

        for(int i = 0; i < counts.length; i++)
        {
            if(counts[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
}
