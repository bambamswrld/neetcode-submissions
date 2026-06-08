class Solution {
    public boolean isAnagram(String s, String t) {
        int[] count = new int[26];
        int sLen = s.length();
        int tLen = t.length();
        int cLen = count.length;
        
        if(sLen != tLen)
        {
            return false;
        }
        
        for(int i = 0; i < sLen; i++)
        {
            count[s.charAt(i) - 'a']++;
            count[t.charAt(i) - 'a']--;
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
