class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int res = 0;

        while(l < r)
        {
            res = std::max((r - l) * std::min(heights[l], heights[r]), res);

            if(heights[l] <= heights[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return res;
    }
};
