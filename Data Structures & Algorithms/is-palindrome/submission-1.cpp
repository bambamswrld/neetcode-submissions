class Solution {
public:
    bool isPalindrome(string s) {
        std::stack<char> stck;
        std::string str;
        auto size = s.size();
        
        for(int i = 0; i < size; i++)
        {
            if(isalnum(s[i]))
            {
                stck.push(tolower(s[i]));
                str.push_back(tolower(s[i]));
            }
        }

        auto strLen = str.size();

        for(int i = 0; i < strLen; i++)
        {
            char top = stck.top();
            if(str[i] != top)
            {
                return false;
            }
            stck.pop();
        }

        return true;
    }
};
