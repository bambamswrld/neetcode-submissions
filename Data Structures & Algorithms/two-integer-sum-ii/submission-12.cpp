class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int begin = 0;
        int end = numbers.size() - 1;

        while(begin < end)
        {
            int sum = numbers[begin] + numbers[end];
            if(sum == target)
            {
                return {begin + 1, end + 1};
            }
            
            if(sum > target)
            {
                end--;
            }
            else
            {
                begin++;
            }
        }
        return {};
    }
};
