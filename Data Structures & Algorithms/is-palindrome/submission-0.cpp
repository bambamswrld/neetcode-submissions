class Solution {
public:
    bool isPalindrome(string s) {
        std::stack<char> stck;
        std::string str;
        auto size = s.size();
        
        bool isPalindrome = true;

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
                isPalindrome = false;
                return isPalindrome;
            }
            stck.pop();
        }

        return isPalindrome;
    }
};
