class Solution {
    public boolean hasDuplicate(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        int len = nums.length;

        for(int i = 0; i < len; i++)
        {
            if(map.containsKey(nums[i]))
            {
                return true;
            }
            map.put(nums[i], i);
        }
        return false;
    }
}