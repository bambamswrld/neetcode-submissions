class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) {return 0;}
        
        int l = 0;
        int r = height.size() - 1;
        int cML = 0;
        int cMR = 0;
        int res = 0;

        while(l < r)
        {
            if(height[l] > cML)
            {
                cML = height[l];
            }
            res += cML - height[l];

            if(height[r] > cMR)
            {
                cMR = height[r];
            }
            res += cMR - height[r];

            if(height[l] < height[r])
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
