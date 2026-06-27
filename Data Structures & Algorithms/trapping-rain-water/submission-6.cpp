class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int lMax = height[l];
        int rMax = height[r];
        int res = 0;
        
        while(l < r)
        {
            if(lMax < rMax)
            {
                l++;
                lMax = std::max(lMax, height[l]);
                res += lMax - height[l];
            }
            else
            {
                r--;
                rMax = std::max(rMax, height[r]);
                res+= rMax - height[r];
            }
        }
        return res;
    }
};
