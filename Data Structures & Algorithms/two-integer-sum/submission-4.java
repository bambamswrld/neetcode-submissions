class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        for(int i = 0; i < nums.length; i++)
        {
            map.put(nums[i], i);
        }

        for(int i = 0; i < nums.length; i++)
        {
            int diff = target - nums[i];
            if(map.containsKey(diff))
            {
                int n = map.get(diff);
                if(n != i)
                {
                    return new int[]{i , n};
                }
            }
        }

        return new int[] {};
    }
}
