class Solution {
public:
    int maxArea(vector<int>& heights) {
        int h = heights.size();
        int res = 0;
        int l = 0;
        int r = 1;
        int area = 0;
        
        for(int l = 0; l < h; l++)
        {
            for(int r = 1; r < h; r++)
            {
                area = (r - l) * std::min(heights[l], heights[r]);

                res = std::max(area, res);
            }    
        }

        return res;
    }
};
