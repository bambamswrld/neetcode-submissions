class Solution {
public:
    int countElements(vector<int>& arr) {
        std::unordered_set<int> numSet(arr.begin(), arr.end());
        int count = 0;
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(numSet.find(arr[i] + 1) != numSet.end())
                count++;
        }

        return count;
    }
};
