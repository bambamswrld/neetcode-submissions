class Solution {
public:
    int countSeniors(vector<string>& strings) {
        int res = 0;
        for(const auto& s : strings)
        {
            int age = std::stoi(s.substr(11, 2));
            if(age > 60) { res++; }
        }
        return res;
    }
};