class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0; i < n; i++)
        {
            int diff = target - numbers[i];
            for(int j = 1; j < n; j++)
            {
                if(numbers[j] == diff)
                {
                    return {i + 1, j + 1};
                }
            }
        }
        return {};
    }
};
