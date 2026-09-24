class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord))
            return 0;

        std::unordered_map<std::string, std::vector<std::string>> patterns;
        std::unordered_set<std::string> visited;
        std::queue<std::string> q;

        for (auto& word : wordList)
        {
            for (auto i = 0; i < word.size(); i++)
            {
                std::string p = word;
                p[i] = '*';
                patterns[p].push_back(word);
            }
        }

        q.push(beginWord);
        visited.insert(beginWord);
        auto steps = 1;

        while (!q.empty())
        {
            auto size = q.size();

            for (auto i = 0; i < size; i++)
            {
                auto word = q.front();
                q.pop();

                if (word == endWord)
                    return steps;

                for (auto j = 0; j < word.size(); j++)
                {
                    std::string p = word;

                    p[j] = '*';
                    
                    for (auto& next : patterns[p])
                    {
                        if (!visited.count(next))
                        {
                            visited.insert(next);
                            q.push(next);
                        }
                    }   
                }
            }
            steps++;
        }
        return 0;
    }
};
