class Solution {
    public boolean isAnagram(String s, String t) {
        char[] sArr = s.toCharArray();
        char[] tArr = t.toCharArray();
        
        Arrays.sort(sArr);
        Arrays.sort(tArr);
        
        int sLen = s.length();
        int tLen = t.length();
        
        if(sLen != tLen)
        {
            return false;
        }

        return Arrays.equals(sArr, tArr);
    }
}
