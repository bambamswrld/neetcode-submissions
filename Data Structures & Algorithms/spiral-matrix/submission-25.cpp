class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        int top = 0, left = 0, bottom = ROWS - 1, right = COLS - 1;
        std::vector<int> res;

        while (top <= bottom && left <= right)
        {
            for (int c = left; c <= right; c++)
                res.push_back(matrix[top][c]);
            top++;

            for (int r = top; r <= bottom; r++)
                res.push_back(matrix[r][right]);
            right--;

            if (top > bottom || left > right)
                break;

            for (int c = right; c >= left; c--)
                res.push_back(matrix[bottom][c]);
            bottom--;

            for (int r = bottom; r >= top; r--)
                res.push_back(matrix[r][left]);
            left++;
        }

        return res;
    }
};
