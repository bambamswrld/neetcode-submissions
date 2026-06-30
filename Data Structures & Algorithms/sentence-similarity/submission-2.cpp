class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size()) {return false;}
        
        std::unordered_map<string, std::unordered_set<string>> map;
        
        for(auto& pair : similarPairs)
        {
            map[pair[0]].insert(pair[1]);
            map[pair[1]].insert(pair[0]);
        }

        for(int i = 0; i < sentence1.size(); i++)
        {
            if(sentence1[i] == sentence2[i])
            {
                continue;
            }

            if(map[sentence1[i]].count(sentence2[i]))
            {
                continue;
            }

            return false;
        }

        return true;
    }
};
