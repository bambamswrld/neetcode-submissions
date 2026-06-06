class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        int len = nums.length;
        
        for(int i = 0; i < len; i++)
        {
            int diff = target - nums[i];
            if(map.containsKey(diff))
            {
                return new int[] {map.get(diff), i};
            }
            map.put(nums[i], i);
        }

        return new int[] {};
    }
}
