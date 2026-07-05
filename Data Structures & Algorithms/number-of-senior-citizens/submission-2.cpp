class Solution {
public:
    int countSeniors(vector<string>& strings) {
        std::vector<int> count;
        int res = 0;
        for(auto& s : strings)
        {
            count.push_back(std::stoi(s.substr(11, 2)));
        }
        
        for(int i = 0; i < count.size(); i++)
        {
            if(count[i] > 60)
            {
                res++;
            }
        }

        return res;
    }
};