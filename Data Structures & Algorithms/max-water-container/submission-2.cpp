class Solution {
public:
    int maxArea(vector<int>& heights) {
        int h = heights.size();
        int l = 0;
        int r = h - 1;
        int res = 0;
        int area = 0;

        while(l < r)
        {
            area = (r - l) * std::min(heights[l], heights[r]);
            res = std::max(area, res);

            if(heights[l] < heights[r])
            {
                l++;
            }
            else if(heights[r] < heights[l])
            {
                r--;
            }
            else
            {
                l++;
                r--;
            }
        }
        return res;
    }
};
