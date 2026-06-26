class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++)
        {
            std::unordered_set<char> seen;
            for(int i = 0; i < 9; i++)
            {
                auto c = board[row][i];
                if(c == '.')
                {
                    continue;
                }
                if(seen.count(c))
                {
                    return false;
                }
                seen.insert(c);
            }
        }

        for(int col = 0; col < 9; col++)
        {
            std::unordered_set<char> seen;
            for(int i = 0; i < 9; i++)
            {
                auto c = board[i][col];
                if(c == '.')
                {
                    continue;
                }
                if(seen.count(c))
                {
                    return false;
                }
                seen.insert(c);
            }
        }

        for(int square = 0; square < 9; square++)
        {
            std::unordered_set<char> seen;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    auto c = board[row][col];
                    if(c == '.')
                    {
                        continue;
                    }
                    if(seen.count(c))
                    {
                        return false;
                    }
                    seen.insert(c);
                }
            }
        }

        return true;
    }
};
