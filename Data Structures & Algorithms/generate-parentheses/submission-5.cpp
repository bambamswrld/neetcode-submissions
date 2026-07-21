class Solution {
private:
    std::vector<string> res;
    void dfs(int n, std::string current, int lCount, int rCount)
    {
        if(lCount == n && rCount == n)
        {
            res.push_back(current);
            return;
        }

        if(lCount < n)
        {
            current += '(';
            dfs(n, current, lCount + 1, rCount);
            current.pop_back();
        }

        if(rCount < lCount)
        {
            current += ')';
            dfs(n, current, lCount, rCount + 1);
            current.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        res.clear();
        std::string current;
        dfs(n, current, 0, 0);
        return res;
    }
};
