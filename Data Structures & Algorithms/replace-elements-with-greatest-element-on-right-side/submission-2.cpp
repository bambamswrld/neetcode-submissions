class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size(), rightMax = -1;
        std::vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--)
        {
            ans[i] = rightMax;
            rightMax = std::max(arr[i], rightMax);
        }

        return ans;
    }
};