class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int l = 0;
        int r = m - 1;

        while(l < r)
        {
            for(int i = 0; i < r - l; i++)
            {
                int top = l;
                int bottom = r;
                int topLeft = matrix[top][l + i];
                
                matrix[top][l + i] = matrix[bottom - i][l];

                matrix[bottom - i][l] = matrix[bottom][r - i];
                
                matrix[bottom][r - i] = matrix[top + i][r];
                
                matrix[top + i][r] = topLeft;
            }
            r--;
            l++;
        }
    }
};
